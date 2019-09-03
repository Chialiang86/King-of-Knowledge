#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostInfo>
#include <QHostAddress>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTimer>
#include <QIODevice>
#include <QFile>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QRandomGenerator>
#include "musicinfo.h"
#include "choosepage.h"
#include "menuwindow.h"
#include "question.h"
#include "packageinfo.h"
#include "dashboard.h"
#include "timeshow.h"
using namespace  Package;

#define GOOD QMessageBox::information(this,"good","good")
#define BAD QMessageBox::warning(this,"nope","BAD",QMessageBox::Yes|QMessageBox::Ok)
#define TIME_UNIT 100
#define MAX_COUNT_NUM 100

namespace Ui {
class MainWindow;
}

typedef struct QuestionString{
    QString str;
    bool legal;
}QueString;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,Package::PlayerKey = Package::server);
    void buildBase();
    void openQuestionFile();
    QString newQuestion();

public slots:
    void connectSettingInit(Package::PlayerKey);
    void accept();
    void parsePackage(const QString&,Package::PlayerKey );
    void serverGetPackage();
    void clientGetPackage();
    void windowShow();
    void nextTimeout();
    void serverQuestionTimeout();
    void resultTimeout();
    void getIPAddr(const QString&);
    void getTrueFalse(const QByteArray&);
    void resizeEvent(QResizeEvent* event);

    void getEditClicked();
    void getPlayer1Clicked();
    void getPlayer2Clicked();

signals:
    void sendNewQuestion(const QString&);//client
    void sendQuestionShow();//client
    void sendConnectSuccess(const QString&);


private:
    bool changeEnabled;

    ObjectOutwardInfo *oi;
    ChoosePage * choose;
    MenuWindow * menu;
    Question *q_page;
    QTimer *next_timer;
    QTimer *question_timer;
    QTimer *result_timer;
    QList<QueString> question_list;
    music_info::tone_base tone[2][12];
    Package::PlayerKey role;
    DashBoard * left_dash;
    DashBoard * right_dash;
    TimeShow * time_show;


    //client
    QTcpSocket *client;

    //server
    QTcpServer *host;
    QTcpSocket *client_socket;

};

#endif // MAINWINDOW_H
