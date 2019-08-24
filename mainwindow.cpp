#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,Package::PlayerKey key) :
    QMainWindow(parent),role(key)
{
    //preprocess
    changeEnabled = false;
    oi = new ObjectOutwardInfo();//all about pos,size,font,color... info
    QPalette bg_pal;
    bg_pal.setBrush(QPalette::Background,oi->background_img);
    this->resize(oi->main->w,oi->main->h);
    this->hide();
    this->setPalette(bg_pal);
    this->setAutoFillBackground(true);
    buildBase();


    //menu window info
    menu = new MenuWindow(nullptr,role);
    connectSettingInit(role);

    //main window info
    q_page = new Question(this);
    left_dash = new DashBoard(this);
    left_dash->setGeometry(oi->left_dashbord->getRect());
    left_dash->initialObject();
    left_dash->show();
    right_dash = new DashBoard(this);
    right_dash->setGeometry(oi->right_dashbord->getRect());
    right_dash->initialObject();
    right_dash->show();

    if(role == Package::server){
        openQuestionFile();
        next_timer = new QTimer();
        next_timer->setInterval(1200);
        next_timer->stop();

        question_timer = new QTimer();
        question_timer->setInterval(10000);
        question_timer->stop();

        result_timer = new QTimer();
        result_timer->setInterval(1200);

        qsrand(QDateTime::currentDateTime().toTime_t());

        connect(next_timer,SIGNAL(timeout()),this,SLOT(nextTimeout()));
        connect(question_timer,SIGNAL(timeout()),this,SLOT(serverQuestionTimeout()));
        connect(result_timer,SIGNAL(timeout()),this,SLOT(resultTimeout()));
    }

    connect(this,SIGNAL(sendQuestionShow()),q_page,SLOT(getQuestionShow()));
    connect(menu,SIGNAL(sendIPAddr(const QString&)),this,SLOT(getIPAddr(const QString&)));
    connect(this,SIGNAL(sendConnectSuccess(const QString&)),menu,SLOT(getConnectSuccess(const QString&)));
    connect(menu,SIGNAL(ready()),this,SLOT(windowShow()));
    connect(this,SIGNAL(sendNewQuestion(const QString&)),q_page,SLOT(getNewQuestion(const QString&)));
    connect(q_page,SIGNAL(sendTrueFalse(const QByteArray&)),this,SLOT(getTrueFalse(const QByteArray&)));

    changeEnabled = true;
}

void MainWindow::resizeEvent(QResizeEvent* event){
    if(changeEnabled){
        oi->setMainwindowNewSize(this->width(),this->height());
        q_page->setGeometry(oi->q_page->getRect());
        left_dash->setGeometry(oi->left_dashbord->getRect());
        right_dash->setGeometry(oi->right_dashbord->getRect());

        q_page->getWindowSizeChange(this->width(),this->height());
        left_dash->getWindowSizeChange(this->width(),this->height());
        right_dash->getWindowSizeChange(this->width(),this->height());
    }
}

void MainWindow::openQuestionFile()
{
    QString path = ":/file/src/file/question.txt";
    QFile qin(path);
    if(qin.open(QIODevice::ReadOnly)){
        //GOOD;
        QueString temp;
        while(!qin.atEnd()){
            temp.str = qin.readLine();
            temp.legal = true;
            question_list.append(temp);
            qDebug() << question_list.back().str;
        }
        qin.close();
    }else{BAD;}
}

void MainWindow::connectSettingInit(Package::PlayerKey key)
{
    if(key == Package::server){
        QString ip;
        QHostInfo host_info = QHostInfo::fromName(QHostInfo::localHostName());
        QHostAddress address = host_info.addresses().first();
        ip = address.toString();
        menu->setIpText(ip);

        host = new QTcpServer(this);
        host->listen(QHostAddress::Any,Package::port1);
        connect(host,SIGNAL(newConnection()),this,SLOT(accept()));
    }else{ //client
        client = new QTcpSocket(this);
        connect(client,SIGNAL(readyRead()),this,SLOT(clientGetPackage()));
    }
}

void MainWindow::getIPAddr(const QString& ip)
{
    QString addr;
    QHostInfo host_info = QHostInfo::fromName(QHostInfo::localHostName());
    QHostAddress address = host_info.addresses().first();
    addr = address.toString();
    QByteArray client_addr_info;
    client_addr_info.append(addr);
    //client 1
    client->connectToHost(ip,Package::port1);
    client->write(PackageInfo::setPackage(Package::title_connect,menu->getPlayerName()));
}

void MainWindow::accept()
{
    //server 2
    client_socket = host->nextPendingConnection();
    connect(client_socket,SIGNAL(readyRead()),this,SLOT(serverGetPackage()));
    QString message = "Connection success! \nPlease push the START button";
    emit sendConnectSuccess(message);
}

void MainWindow::serverGetPackage()
{
    //server 3
    parsePackage(QString(client_socket->readAll()),role);

}

void MainWindow::clientGetPackage()
{
    //client 4
     parsePackage(QString(client->readAll()),role);
}


void MainWindow::parsePackage(const QString& pack,Package::PlayerKey key){
    Package::PackageInfo pinfo;
    pinfo.setTitle(pack.split(Package::colon).at(0));
    pinfo.setInstruct(pack.split(Package::colon).at(1));
    if(key == Package::client){
        qDebug() << " client :" << pinfo.getTitle() << " " << pinfo.getInstruct() << endl;
        if(pinfo.getTitle() == Package::title_connect){
            menu->hide();
            this->show();
            left_dash->setPlayerName(menu->getPlayerName());
            right_dash->setPlayerName(pinfo.getInstruct());
            q_page->reset();
        }
        else if(pinfo.getTitle() == Package::title_question){
            emit sendNewQuestion(pinfo.getInstruct());
        }
        else if(pinfo.getTitle() == Package::title_result){
            q_page->reset();
        }
        else if(pinfo.getTitle() == Package::title_next){
            emit sendQuestionShow();
        }
        else if(pinfo.getTitle() == Package::title_player){
            right_dash->setPlayerScore(pinfo.getInstruct().split(Package::comma).at(1));
        }
        else if(pinfo.getTitle() == Package::title_gameover){
            QString winner = pinfo.getInstruct().split(Package::comma).at(0);
            QString score = pinfo.getInstruct().split(Package::comma).at(1);
            q_page->setGameOverText(winner, score);
        }
    }else{
        qDebug() << " client :" << pinfo.getTitle() << " " << pinfo.getInstruct() << endl;
        if(pinfo.getTitle() == Package::title_connect){
            right_dash->setPlayerName(pinfo.getInstruct());
        }
        else if(pinfo.getTitle() == Package::title_player){
            right_dash->setPlayerScore(pinfo.getInstruct().split(Package::comma).at(1));
        }
    }
}

void MainWindow::windowShow()
{
    //send to client done
    if(role == Package::server){
        result_timer->start();
        menu->hide();
        this->show();
        left_dash->setPlayerName(menu->getPlayerName());
        q_page->reset();
        client_socket->write(PackageInfo::setPackage(title_connect,menu->getPlayerName()));
    }
}

void MainWindow::nextTimeout() // to question
{
    //send to client done
    emit sendQuestionShow();
    client_socket->write( PackageInfo::setPackage(title_next,"show question"));

    next_timer->stop();
    question_timer->start();
}

void MainWindow::serverQuestionTimeout() // to result
{
    //send to client done
    question_timer->stop();
    result_timer->start();

    client_socket->write(PackageInfo::setPackage(title_result,"show correct"));
    q_page->reset();
}


void MainWindow::resultTimeout() // to next
{
    //send to client
    if(q_page->getQuestionCounter() < 5){
        QString question = newQuestion();
        emit sendNewQuestion(question);
        client_socket->write(PackageInfo::setPackage(title_question,question));
        result_timer->stop();
        next_timer->start();
    }else{
        result_timer->stop();
        if(left_dash->getScore().toInt() > right_dash->getScore().toInt()){
            QString winner_ins = left_dash->getPlayerName() + Package::comma + left_dash->getScore();
            QByteArray winner_info;
            winner_info = PackageInfo::setPackage(Package::title_gameover,winner_ins);
            client_socket->write(winner_info);
            q_page->setGameOverText(left_dash->getPlayerName(), left_dash->getScore());
            qDebug() << winner_info << endl;
        }else{
            QString winner_ins = right_dash->getPlayerName() + Package::comma + right_dash->getScore();
            QByteArray winner_info;
            winner_info = PackageInfo::setPackage(Package::title_gameover,winner_ins);
            client_socket->write(winner_info);
            q_page->setGameOverText(right_dash->getPlayerName(), right_dash->getScore());
            qDebug() << winner_info << endl;
        }
    }

}


void MainWindow::getTrueFalse(const QByteArray& msg)
{
    //bi communication
    if(role == Package::server){
        QString title = PackageInfo::parseTitle(msg);
        QString ins = PackageInfo::parseInstruct(msg);
        left_dash->setPlayerScore(ins.split(Package::comma).at(1));
        client_socket->write(msg);

    }else{
        QString title = PackageInfo::parseTitle(msg);
        QString ins = PackageInfo::parseInstruct(msg);
        left_dash->setPlayerScore(ins.split(Package::comma).at(1));
        client->write(msg);
    }
}



QString MainWindow::newQuestion()
{
    int legal_index;
    QString true_question;
    do{
        legal_index = qrand() % question_list.length();
    }while(!question_list.at(legal_index).legal);
    question_list[legal_index].legal = false;
    true_question = question_list.at(legal_index).str.split(Package::colon).at(1);
    return true_question;
}

void MainWindow::buildBase()
{
    for(int type = 0 ;type < 2; ++type){
        for(int t = 0 ; t < 12 ; ++t){
            tone[type][t].tone = music_info::ToneTable[type][t];
            tone[type][t].type = type == 0 ? music_info::flat : music_info::sharp;
        }
    }
}


