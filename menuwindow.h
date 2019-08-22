#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include "objectoutwardinfo.h"
#include "questionbutton.h"
#include "packageinfo.h"

class MenuWindow : public QWidget {
    Q_OBJECT
  public:
    MenuWindow(QWidget *,Package::PlayerKey);
    void debug();
    void setIpText(QString&);
    void serverActive();
    void clientActive();
    bool inputNotEmpty();
    bool stringEmpty(const QString&);
    bool ipIsLegal();
    QString getPlayerName();

  public slots:
    void startBtnClicked();
    void getConnectSuccess(const QString&);

  signals:
    void ready();
    void sendIPAddr(const QString& ip);


  private :
    ObjectOutwardInfo * oi;
    Package::PlayerKey player_key;

    QLineEdit * player_name;
    QLabel * player_guide;

    QLabel * ip_guide;
    QLabel * ip_show;
    QLineEdit * ip_input;

    QLabel * start_guide;
    QPushButton * start_btn;
    //QString player_name;
};

#endif // MENUWINDOW_H
