#include "menuwindow.h"

MenuWindow::MenuWindow(QWidget * parent,Package::PlayerKey key) : QWidget(parent)
    ,player_key(key) {

    oi = new ObjectOutwardInfo();
    this->resize(oi->menu->w,oi->menu->h);
    this->setFont(QFont("Courier",14));
    this->show();

    if(player_key == Package::server)
        serverActive();
    else
        clientActive();

}

void MenuWindow::serverActive() {
    player_guide = new QLabel(this);
    player_guide->setGeometry(oi->pname_guide->x,oi->pname_guide->y,oi->pname_guide->w,oi->pname_guide->h);
    player_guide->setFont(*oi->textshow);
    player_guide->setText("Please input your name below.");
    player_guide->setAlignment(Qt::AlignCenter);
    player_guide->show();

    player_name = new QLineEdit(this);
    player_name->setGeometry(oi->pname->x,oi->pname->y,oi->pname->w,oi->pname->h);
    player_name->setFont(*oi->textinput);
    player_name->setStyleSheet(oi->line_edit_stylesheet);
    player_name->setAlignment(Qt::AlignCenter);
    player_name->show();

    ip_guide = new QLabel(this);
    ip_guide->setGeometry(oi->ip_guide->x,oi->ip_guide->y,oi->ip_guide->w,oi->ip_guide->h);
    ip_guide->setFont(*oi->textshow);
    ip_guide->setText("Please tell the client your IP.");
    ip_guide->setAlignment(Qt::AlignCenter);
    ip_guide->show();

    ip_show = new QLabel(this);
    ip_show->setGeometry(oi->ip->x,oi->ip->y,oi->ip->w,oi->ip->h);
    ip_show->setFont(*oi->textshow);
    ip_show->setStyleSheet(oi->label_stylesheet);
    ip_show->setAlignment(Qt::AlignCenter);
    ip_show->show();

    start_guide = new QLabel(this);
    start_guide->setGeometry(oi->start_guide->x,oi->start_guide->y,oi->start_guide->w,oi->start_guide->h);
    start_guide->setFont(*oi->textshow);
    start_guide->setText("If ready, press START button.");
    start_guide->setAlignment(Qt::AlignCenter);
    start_guide->hide();

    start_btn = new QPushButton(this);
    start_btn->setGeometry(oi->start->x,oi->start->y,oi->start->w,oi->start->h);
    start_btn->setFont(*oi->textshow);
    start_btn->setStyleSheet(oi->button_stylesheet);
    start_btn->setText("START");
    start_btn->hide();

    connect(start_btn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
}
void MenuWindow::clientActive() {
    player_guide = new QLabel(this);
    player_guide->setGeometry(oi->pname_guide->x,oi->pname_guide->y,oi->pname_guide->w,oi->pname_guide->h);
    player_guide->setFont(*oi->textshow);
    player_guide->setText("Please input your name below.");
    player_guide->setAlignment(Qt::AlignCenter);
    player_guide->show();

    player_name = new QLineEdit(this);
    player_name->setGeometry(oi->pname->x,oi->pname->y,oi->pname->w,oi->pname->h);
    player_name->setFont(*oi->textinput);
    player_name->setStyleSheet(oi->line_edit_stylesheet);
    player_name->setAlignment(Qt::AlignCenter);
    player_name->show();

    ip_guide = new QLabel(this);
    ip_guide->setGeometry(oi->ip_guide->x,oi->ip_guide->y,oi->ip_guide->w,oi->ip_guide->h);
    ip_guide->setFont(*oi->textshow);
    ip_guide->setText("Please input the server IP");
    ip_guide->setAlignment(Qt::AlignCenter);
    ip_guide->show();

    ip_input = new QLineEdit(this);
    ip_input->setGeometry(oi->ip->x, oi->ip->y, oi->ip->w, oi->ip->h);
    ip_input->setFont(*oi->textshow);
    ip_input->setStyleSheet(oi->line_edit_stylesheet);
    ip_input->setAlignment(Qt::AlignCenter);
    ip_input->show();

    start_guide = new QLabel(this);
    start_guide->setGeometry(oi->start_guide->x,oi->start_guide->y,oi->start_guide->w,oi->start_guide->h);
    start_guide->setFont(*oi->textshow);
    start_guide->setText("If ready, press OK button.");
    start_guide->setAlignment(Qt::AlignCenter);
    start_guide->show();

    start_btn = new QPushButton(this);
    start_btn->setGeometry(oi->start->x,oi->start->y,oi->start->w,oi->start->h);
    start_btn->setFont(*oi->textshow);
    start_btn->setStyleSheet(oi->button_stylesheet);
    start_btn->setText("OK");
    start_btn->show();

    connect(start_btn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
}

QString MenuWindow::getPlayerName() {
    if(player_name->text() != "")
        return player_name->text();
    else {
        return QString("ERROR");
    }
}

void MenuWindow::setIpText(QString& ip_pos) {
    if(player_key == Package::server) {
        ip_show->setText(ip_pos);
        ip_show->update();
    }
}

void MenuWindow::startBtnClicked() {
    if(player_key == Package::server) {
        //player_name = player_name->text();
        if(inputNotEmpty()) {
            this->hide();
            emit ready();
        } else {
            QMessageBox::warning(this,"nope","illegal input",QMessageBox::Ok);
        }
    } else {
        if(inputNotEmpty()) {
            emit sendIPAddr(ip_input->text());
        } else {
            QMessageBox::warning(this,"nope","illegal input",QMessageBox::Ok);
        }
    }
}

void MenuWindow::getConnectSuccess(const QString& message) {
    if(player_key == Package::server) {
        start_guide->setText(message);
        start_guide->show();
        start_btn->show();
    } else {
        start_guide->setText(message);
        start_btn->hide();
    }
}

bool MenuWindow::inputNotEmpty() {
    if(player_key == Package::server) {
        if(stringEmpty(player_name->text()))
            return false;
        else
            return true;
    } else {
        if(stringEmpty(player_name->text()) || !ipIsLegal())
            return false;
        else
            return true;
    }
}

bool MenuWindow::stringEmpty(const QString& str) {
    if(str == "")
        return true;
    else {
        for(int i = 0; i < str.length(); ++i)
            if(str[i] != ' ')
                return false;
        return true;
    }
}

bool MenuWindow::ipIsLegal() {
    QString str_clear_space = "";
    for(int i = 0 ; i < ip_input->text().length(); ++i)
        if(ip_input->text().at(i) != ' ')
            str_clear_space += ip_input->text().at(i);
    ip_input->setText(str_clear_space);
    if(str_clear_space.split('.').length() != 4)
        return false;
    else {
        for(int i = 0 ; i < 4; ++i) {
            for(int j = 0 ; j < str_clear_space.split('.').at(i).length(); ++j) {
                if( str_clear_space.split('.').at(i).at(j) < 48 ||
                        str_clear_space.split('.').at(i).at(j) > 57)
                    return false;
            }
        }
    }
    return true;
}

void MenuWindow::debug() {
}
