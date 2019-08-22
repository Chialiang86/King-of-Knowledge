#include "dashboard.h"

DashBoard::DashBoard(QWidget * parent) : QFrame(parent) {
    oi = new ObjectOutwardInfo();
    this->setStyleSheet(oi->dashboard_stylesheet);
    this->show();
    score = 0;

}

void DashBoard::initialObject() {
    player_name = new QLabel(this);
    player_name->setGeometry(oi->p_label->x,oi->p_label->y,oi->p_label->w,oi->p_label->h);
    player_name->setFont(*oi->textshow);
    player_name->setText("name");
    player_name->setAlignment(Qt::AlignCenter);
    player_name->show();

    player_hist = new HistFrame(this);
    player_hist->show();

    player_score = new QLabel(this);
    player_score->setGeometry(oi->pscore_label->x,oi->pscore_label->y,oi->pscore_label->w,oi->pscore_label->h);
    player_score->setFont(*oi->textshow);
    player_score->setText("score");
    player_score->setAlignment(Qt::AlignCenter);
    player_score->show();
}


void DashBoard::setPlayerName(const QString& name) {
    player_name->setText(name);
}

void DashBoard::setPlayerHist(double ratio) {
    player_hist->setHist(ratio);
}

QString  DashBoard::getScore() {
    return player_score->text();
}

QString DashBoard::getPlayerName() {
    return player_name->text();
}

void DashBoard::setPlayerScore(const QString& add) {
    int add_num = add.toInt();
    score += add_num;
    player_score->setText(QString::number(score));
    if(score <= 2000) {
        double ratio = static_cast<double>(score) / 2000;
        player_hist->setHist(ratio);
    }
}

void DashBoard::setPlayerScore(int add) {
    score += add;
    player_score->setText(QString::number(score));
    if(score <= 2000) {
        double ratio = static_cast<double>(score) / 2000;
        player_hist->setHist(ratio);
    }
}
