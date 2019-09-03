#include "choosepage.h"

ChoosePage::ChoosePage(QWidget * parent) : QWidget (parent)
{
    oi = new ObjectOutwardInfo();
    this->resize(oi->choose->w,oi->choose->h);
    QPalette menu_pal;
    menu_pal.setBrush(QPalette::Background,oi->menu_img);
    this->setPalette(menu_pal);
    this->show();

    logo_label = new QLabel(this);
    logo_label->setGeometry(oi->loso_label->getRect());
    logo_label->setStyleSheet(oi->logo_stylesheet);
    logo_label->show();

    edit_btn = new QPushButton(this);
    edit_btn->setGeometry(oi->edit_btn->getRect());
    edit_btn->setFont(*oi->textshow);
    edit_btn->setStyleSheet(oi->button_stylesheet);
    edit_btn->setText("編輯題目");
    edit_btn->show();

    play_btn = new QPushButton(this);
    play_btn->setGeometry(oi->play_btn->getRect());
    play_btn->setFont(*oi->textshow);
    play_btn->setStyleSheet(oi->button_stylesheet);
    play_btn->setText("玩遊戲");
    play_btn->show();

    player1_btn = new QPushButton(this);
    player1_btn->setGeometry(oi->player1_btn->getRect());
    player1_btn->setFont(*oi->textshow);
    player1_btn->setStyleSheet(oi->button_stylesheet);
    player1_btn->setText("1 player");
    player1_btn->hide();

    player2_btn = new QPushButton(this);
    player2_btn->setGeometry(oi->player2_btn->getRect());
    player2_btn->setFont(*oi->textshow);
    player2_btn->setStyleSheet(oi->button_stylesheet);
    player2_btn->setText("2 players");
    player2_btn->hide();


    connect(this->edit_btn,SIGNAL(clicked()),this,SLOT(chooseEdit()));
    connect(this->play_btn,SIGNAL(clicked()),this,SLOT(choosePlay()));
    connect(this->player1_btn,SIGNAL(clicked()),this,SLOT(allDone()));
    connect(this->player2_btn,SIGNAL(clicked()),this,SLOT(allDone()));

}

void ChoosePage::chooseEdit()
{
    this->close();
}

void ChoosePage::choosePlay()
{
    edit_btn->hide();
    play_btn->hide();
    player1_btn->show();
    player2_btn->show();
}

void ChoosePage::allDone()
{
    this->close();
}
