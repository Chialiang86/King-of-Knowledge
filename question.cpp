#include "question.h"

Question::Question(QWidget * parent) : QFrame(parent)
{
    oi = new ObjectOutwardInfo();
    this->setGeometry(oi->q_page->getRect());
    this->autoFillBackground();
    this->show();
    this->setStyleSheet(oi->q_page_stylesheet);

    question = new QLabel(this);
    question->setGeometry(oi->q_label->getRect());
    question->setFont(*oi->message);
    question->setAlignment(Qt::AlignCenter);
    question->setText(tr("這是題目"));
    question->show();

    answer1 = new QuestionButton(this);
    answer1->setGeometry(oi->a1_button->getRect());
    answer1->setText("1btn");

    answer2 = new QuestionButton(this);
    answer2->setGeometry(oi->a2_button->getRect());
    answer2->setText("2btn");

    answer3 = new QuestionButton(this);
    answer3->setGeometry(oi->a3_button->getRect());
    answer3->setText("3btn");

    answer4 = new QuestionButton(this);
    answer4->setGeometry(oi->a4_button->getRect());
    answer4->setText("4btn");

    next = new QLabel(this);
    next->setGeometry(oi->next_label->getRect());
    next->setFont(*oi->next);
    next->setStyleSheet(oi->label_stylesheet);
    next->setAlignment(Qt::AlignCenter);
    next->hide();

    score_timer = new ScoreTimer();

    question_counter = 0;

    connect(answer1,SIGNAL(clicked()),this,SLOT(answer1Click()));
    connect(answer2,SIGNAL(clicked()),this,SLOT(answer2Click()));
    connect(answer3,SIGNAL(clicked()),this,SLOT(answer3Click()));
    connect(answer4,SIGNAL(clicked()),this,SLOT(answer4Click()));

}


void Question::getWindowSizeChange(int neww,int newh)
{
    oi->setQPageNewSize(neww,newh);

    question->setGeometry(oi->q_label->getRect());
    question->setFont(*oi->message);
    answer1->setGeometry(oi->a1_button->getRect());
    answer1->setFont(*oi->textshow);
    answer2->setGeometry(oi->a2_button->getRect());
    answer2->setFont(*oi->textshow);
    answer3->setGeometry(oi->a3_button->getRect());
    answer3->setFont(*oi->textshow);
    answer4->setGeometry(oi->a4_button->getRect());
    answer4->setFont(*oi->textshow);
    next->setGeometry(oi->next_label->getRect());
    next->setFont(*oi->next);
}

void Question::reset()
{
    score_timer->reset();
    question->setText("");
    question->hide();
    answer1->reset();
    answer2->reset();
    answer3->reset();
    answer4->reset();
}

 void Question::done()
 {
     score_timer->stop();
     answer1->done();
     answer2->done();
     answer3->done();
     answer4->done();
 }

void Question::getNewQuestion(const QString &str)
{
    parseQuestion(str.split(Package::end).at(0));
}

void Question::parseQuestion(const QString& str)
{
    if(question_counter < 5)
        ++ question_counter;
    else
        QMessageBox::information(this,"warning","Exceed Question num!");

    next->setText(setNextQuestion(str.split(Package::comma).at(0)));
    next->show();

    question->setText (str.split(Package::comma).at(1));
    answer1->setOption(str.split(Package::comma).at(2));
    answer2->setOption(str.split(Package::comma).at(3));
    answer3->setOption(str.split(Package::comma).at(4));
    answer4->setOption(str.split(Package::comma).at(5));
}

int Question::getQuestionCounter()
{
    return question_counter;
}

QString Question::setNextQuestion(const QString& que)
{
    QString next_text;
    next_text = QString(tr("第 %1 題 \n\n %2")).arg(question_counter).arg(que);
    return next_text;
}


void Question::setGameOverText(const QString& winner,const QString& score)
{
    score_timer->stop();
    question->hide();
    answer1->reset();
    answer2->reset();
    answer3->reset();
    answer4->reset();
    QString winner_info = "恭喜 " + winner + " 勝利\n\n" +
                           "得分 ：" + score + " 分";
    next->setText(winner_info);
    next->show();

}

void Question::getQuestionShow()
{
    score_timer->start();
    next->close();
    question->show();
    answer1->show();
    answer2->show();
    answer3->show();
    answer4->show();
}

QString Question::getPlayerInstruct(bool tf){
    return QString(score_timer->getScore(tf,question_counter));
}

void Question::answer1Click()
{
    if(answer1->getEnabled()){
        answer1->showTrueFalse();
        QString score_info = getPlayerInstruct(answer1->trueOrFalse());
        emit sendTrueFalse(PackageInfo::setPackage(title_player,score_info));
        done();
    }
}

void Question::answer2Click()
{
    if(answer2->getEnabled()){
        answer2->showTrueFalse();
        QString score_info = getPlayerInstruct(answer2->trueOrFalse());
        emit sendTrueFalse(PackageInfo::setPackage(title_player,score_info));
        done();
    }
}

void Question::answer3Click()
{
    if(answer3->getEnabled()){
        answer3->showTrueFalse();
        QString score_info = getPlayerInstruct(answer3->trueOrFalse());
        emit sendTrueFalse(PackageInfo::setPackage(title_player,score_info));
        done();
    }
}

void Question::answer4Click()
{
    if(answer4->getEnabled()){
        answer4->showTrueFalse();
        QString score_info = getPlayerInstruct(answer4->trueOrFalse());
        emit sendTrueFalse(PackageInfo::setPackage(title_player,score_info));
        done();
    }
}
