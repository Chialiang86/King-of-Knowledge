#include "dashboard.h"

DashBoard::DashBoard(QWidget * parent) : QFrame(parent)
{
    oi = new ObjectOutwardInfo();
    this->setStyleSheet(oi->dashboard_stylesheet);
    this->show();
    score = 0;

}

void DashBoard::initialObject()
{
    player_name = new QLabel(this);
    player_name->setGeometry(oi->p_label->getRect());
    player_name->setFont(*oi->textshow);
    player_name->setText("name");
    player_name->setAlignment(Qt::AlignCenter);
    player_name->setStyleSheet(oi->show_stylesheet);
    player_name->show();

    player_hist = new HistFrame(this);
    player_hist->show();

    player_score = new QLabel(this);
    player_score->setGeometry(oi->pscore_label->getRect());
    player_score->setFont(*oi->textshow);
    player_score->setText("score");
    player_score->setAlignment(Qt::AlignCenter);
    player_score->setStyleSheet(oi->show_stylesheet);
    player_score->show();
}

void DashBoard::getWindowSizeChange(int neww,int newh)
{
    oi->setDashboardNewSize(neww,newh);
    player_name->setGeometry(oi->p_label->getRect());
    player_name->setFont(*oi->textshow);
    player_hist->setGeometry(oi->phist_label->getRect());
    player_hist->getSizeChanged();
    player_score->setGeometry(oi->pscore_label->getRect());
    player_score->setFont(*oi->textshow);
}


void DashBoard::setPlayerName(const QString& name)
{
    player_name->setText(name);
}

void DashBoard::setPlayerHist(double ratio)
{
    player_hist->setRatio(ratio);
    player_hist->setHist();
}

QString  DashBoard::getScore()
{
    return player_score->text();
}

QString DashBoard::getPlayerName()
{
    return player_name->text();
}

void DashBoard::setPlayerScore(const QString& add)
{
    int add_num = add.toInt();
    score += add_num;
    player_score->setText(QString::number(score));
    if(score <= 2000){
        double ratio = static_cast<double>(score) / 2000;
        player_hist->setRatio(ratio);
        player_hist->setHist();
    }
}

void DashBoard::setPlayerScore(int add)
{
    score += add;
    player_score->setText(QString::number(score));
    if(score <= 2000){
        double ratio = static_cast<double>(score) / 2000;
        player_hist->setRatio(ratio);
        player_hist->setHist();
    }
}
