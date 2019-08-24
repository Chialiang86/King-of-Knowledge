#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QLabel>
#include <QString>
#include <histframe.h>
#include "objectoutwardinfo.h"
#include "packageinfo.h"


class DashBoard : public QFrame
{
    Q_OBJECT
public:
    DashBoard(QWidget * parent = nullptr);
    void initialObject();
    void setPlayerName(const QString&);
    void setPlayerHist(double);
    void setPlayerScore(const QString&);
    void setPlayerScore(int);
    void getWindowSizeChange(int,int);
    QString  getScore();
    QString getPlayerName();

private :
    ObjectOutwardInfo * oi;
    QLabel * player_name;
    HistFrame * player_hist;
    QLabel * player_score;
    int score;
};

#endif // DASHBOARD_H
