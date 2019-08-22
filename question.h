#ifndef QUESTION_H
#define QUESTION_H
#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QTimer>
#include "questionbutton.h"
#include "packageinfo.h"
using namespace Package;

class ScoreTimer : public QTimer{
    Q_OBJECT
public:
    ScoreTimer(){
        reset();
        connect(this,SIGNAL(timeout()),this,SLOT(getTimeOut()));
    }

    void reset(){
        counter = 200;
        this->setInterval(40);
        this->stop();
    }
    QString getScore(bool tf,int q_num){
        double s =  getRatio() * (q_num + base) * unit_max_score;
         QString msg;
         QString num;
        if(tf){
            num = QString::number(static_cast<int>(s));
            msg = "o" + Package::comma + num ;
        }else{
            num = QString::number(0);
            msg = "x" + Package::comma + num ;
        }
        return msg;
    }

    int getMaxScore(){
        return total_max_score;
    }

    double getRatio(){
        double ratio;
        ratio = 1.0 - 0.0000278 * (200 - counter) * (200 - counter);
        return ratio;
    }

    QString getTotalRatio(int score){
        QString ratio = QString::number(static_cast<double>(score) / total_max_score);
        return ratio;
    }

public slots:
    void getTimeOut(){
        counter = counter - 1 >= 30 ? counter - 1 : 20;
        if(counter == 30)
            this->stop();
    }

private:

    int counter;
    static const int total_max_score = 2000;
    static const int unit_max_score = 80;
    static const int base = 2;

};

class Question : public QFrame
{
    Q_OBJECT
public:
    Question(QWidget *);
    ObjectOutwardInfo * oi;
     void reset();
     void done();
public slots:
    void getNewQuestion(const QString&);
    void getQuestionShow();
    void parseQuestion(const QString&);
    void answer1Click();
    void answer2Click();
    void answer3Click();
    void answer4Click();
    void setGameOverText(const QString&,const QString&);
    int getQuestionCounter();
    QString setNextQuestion(const QString&);
    QString getPlayerInstruct(bool);

signals:
    void sendTrueFalse(const QByteArray&);

private:
    int question_counter;
    QLabel * question;
    QLabel * next;
    ScoreTimer * score_timer;
    QuestionButton * answer1;
    QuestionButton * answer2;
    QuestionButton * answer3;
    QuestionButton * answer4;

};

#endif // QUESTION_H
