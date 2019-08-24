#ifndef PACKAGEINFO_H
#define PACKAGEINFO_H
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QDebug>

namespace Package {
typedef enum PlayerKeyKind{client,server}PlayerKey;
const qint16 port1 = 9999;
const qint16 port2 = 6666;
const QString colon = "::";
const QString comma = ",,";
const QString dot = "..";
const QString end = ";";
const QString true_ans = "o";
const QString false_ans = "x";
//Title kind
const QString title_connect  = "connect";
const QString title_next  = "next";
const QString title_question  = "question";
const QString title_player   = "player";
const QString title_result   = "result";
const QString title_gameover = "gameover";


class QuestionGenerate : public QWidget
{
   Q_OBJECT
public :
    QuestionGenerate(QString sub = "", QString que = "",
                     QString a1 = "",QString a2 = "",QString a3 = "",QString a4 = ""){
        if(!isEmpty(sub) && !isEmpty(que) && !isEmpty(a1) &&
           !isEmpty(a2)  && !isEmpty(a3)  && !isEmpty(a4)){
            clear();
        }
        else{
            subject = sub;
            question = que;
            ans[0] = a1;
            ans[1] = a2;
            ans[2] = a3;
            ans[3] = a4;
        }
        err = "ERROR";
    }

    void clear(){
        subject = "";
        question = "";
        for(int i = 0; i < 4 ; ++i){
            ans[i] = "";
        }
    }
    bool isEmpty(const QString& str){
        if(str == "")
            return true;
        else
            return false;
    }

    void setSubject(const QString sub){
        subject = sub;
    }

    void setQuestion(const QString& que){
        question = que;
    }

    void setAns(const int num,const QString& answer,bool is_true){
        if(num < 0 || num > 3){
            QMessageBox::information(this,"error","Illegal q num");
            return ;
        }else{
            if(is_true){
                ans[num] = true_ans + dot + answer;
            }else{
                ans[num] = false_ans + dot + answer;
            }
        }
    }

    QString getQuestionPackage(){
        if(isEmpty(subject) || isEmpty(question)){
            QMessageBox::information(this,"error",err + " sub or que");
            return err;
        }
        for(int i = 0 ; i < 4; ++i){
            if(ans[i].split(dot).length() != 2){
                QMessageBox::information(this,"error",err + " a dot");
                return err;
            }
        }
        QString question_package = "question::";
        question_package += subject + comma;
        question_package += question + comma;
        question_package += ans[0] + comma;
        question_package += ans[1] + comma;
        question_package += ans[2] + comma;
        question_package += ans[3] + end;
        return question_package;
    }

private:
    QString ans[4];
    QString question;
    QString subject;
    QString err;

};


class PackageInfo : public QWidget
{
    Q_OBJECT
public:
    QList<QString> title_name;
    PackageInfo(const QString& pack = ""){
        title_name.append(title_question);
        title_name.append(title_next);
        title_name.append(title_connect);
        title_name.append(title_player);
        title_name.append(title_result);
        title_name.append(title_gameover);
        if(pack != ""){
            title = pack.split(colon).at(0);
            instruct = pack.split(colon).at(1).split(end).at(0);
        }else{
            err = "ERROR";
            title = "";
            instruct = "";
        }

    }
    void setTitle(const QString& t){
        bool legal = false;
        qDebug() << "Title: " << t << endl;
        for(int i = 0 ; i < title_name.length(); ++i){
            if(t == title_name.at(i)){
                legal = true;
                break;
            }
        }
        if(legal)
            title = t;
        else
            QMessageBox::information(this,"error",err + ":set t");
    }


    void setInstruct(const QString& in){
        instruct = in;
    }

    QString getPackage(const QString& t,const QString& in){
        QString package;
        setTitle(t);
        setInstruct(in);
        package = title + colon + instruct ;
        return package;
    }

    QString getPackage(){
        if(!isEmpty(title) && !isEmpty(instruct))
            return title + colon + instruct;
        else{
            QMessageBox::information(this,"error",err + ": empty");
            return err;
        }
    }

    bool isEmpty(const QString& str){
        if(str == "")
            return true;
        else
            return false;
    }

    QString getTitle(){
        if(title != "")
            return title;
        else{
            QMessageBox::information(this,"error",err + ":get t");
            return err;
        }
    }

    QString getInstruct(){
        if(instruct != "")
            return instruct;
        else{
            QMessageBox::information(this,"error",err + ":get i");
            return err;
        }
    }

    static QByteArray setPackage(const QString& ti,const QString& in)
    {
        PackageInfo client_show;
        QByteArray client_show_msg;
        client_show_msg.append(client_show.getPackage(ti,in));
        return client_show_msg;
    }
    static QString parseInstruct(const QString& package)
    {
        QString p(package);
        return QString(p.split(colon).at(1));
    }

    static QString parseTitle(const QString& package)
    {
        QString p(package);
        return QString(p.split(colon).at(0));
    }

private:
    QString err;
    QString title;
    QString instruct;

};



}
#endif // PACKAGEINFO_H
