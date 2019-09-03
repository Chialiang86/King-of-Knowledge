#include "timeshow.h"

TimeShow::TimeShow(QWidget * parent,int max,int unit) : QFrame (parent)
{
    max_num = max;
    time_unit = unit;
    time_counter = max_num;
    oi = new ObjectOutwardInfo();

    this->setGeometry(oi->time_show_frame->getRect());
    this->show();

    time_text = new QLabel(this);
    time_text->setGeometry(oi->time_text_label->getRect());
    time_text->setFont(*oi->textshow);
    time_text->setText(QString("剩 %1 秒").arg(trueSecond(max_num)));
    time_text->setAlignment(Qt::AlignHCenter);
    time_text->show();

    time_hist = new QLabel(this);
    time_hist->setGeometry(oi->time_hist_label->getRect());
    time_hist->setStyleSheet(oi->time_hist_green_stylesheet);
    time_hist->show();

    time_rate = 1.0;
}

void TimeShow::getWindowSizeChange(int neww,int newh)
{
    oi->setTimerShowNewSize(neww,newh);
    time_text->setGeometry(oi->time_text_label->getRect());
    time_text->setFont(*oi->textshow);
    QRect hist = oi->time_hist_label->getRect();
    hist.setWidth(static_cast<int>(time_rate * hist.width()));
    time_hist->setGeometry(hist);
}

void TimeShow::setMaxCountNum(int num)
{
    max_num = num;
}

void TimeShow::updateTime()
{
    if(time_counter <= 0){
        time_text->setText(QString("剩 %1 秒").arg(trueSecond(max_num)));
        time_text->update();
        QMessageBox::information(this,"error","EXCEED NUM");
    }else{
        time_text->setText(QString("剩 %1 秒").arg(trueSecond(--time_counter)));
        time_text->update();
        time_rate = static_cast<double>(time_counter) / max_num;
        if(time_rate < 0.2)
            time_hist->setStyleSheet(oi->time_hist_red_stylesheet);
        QRect hist = oi->time_hist_label->getRect();
        hist.setWidth(static_cast<int>(time_rate * hist.width()));
        time_hist->setGeometry(hist);
        time_hist->update();
    }
}

void TimeShow::resetTime()
{
    time_counter = max_num;
    time_text->setText(QString("剩 %1 秒").arg(trueSecond(time_counter)));
    time_hist->setStyleSheet(oi->time_hist_green_stylesheet);
    time_hist->setGeometry(oi->time_hist_label->getRect());
}

double TimeShow::trueSecond(int t)
{
    return (t * time_unit / 1000 + 1 == 11) ? 10 : (t * time_unit / 1000 + 1);
}

 int TimeShow::getTime()
 {
     return time_counter;
 }

