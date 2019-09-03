#ifndef TIMESHOW_H
#define TIMESHOW_H
#include <QLabel>
#include <QMessageBox>
#include "objectoutwardinfo.h"

class TimeShow : public QFrame
{
    Q_OBJECT
public:
    TimeShow(QWidget * parent = nullptr, int max = 100, int unit = 100);
    void updateTime();
    void resetTime();
    void setMaxCountNum(int);
    void getWindowSizeChange(int,int);
    int getTime();
    double trueSecond(int);
private:
    ObjectOutwardInfo *oi;
    QLabel * time_text;
    QLabel * time_hist;
    double time_rate;
    int time_counter;
    int time_unit;
    int max_num;
};

#endif // TIMESHOW_H
