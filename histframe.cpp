#include "histframe.h"

HistFrame::HistFrame(QWidget * parent) : QFrame (parent)
{
    oi = new ObjectOutwardInfo();
    this->setGeometry(oi->phist_label->x,oi->phist_label->y,oi->phist_label->w,oi->phist_label->h);
    this->setStyleSheet(oi->hist_frame_stylesheet);

    length = 2;
    graph = new QLabel(this);
    graph->setGeometry(0,oi->phist_label->h - length,oi->phist_label->w,oi->phist_label->h);
    graph->setStyleSheet(oi->hist_stylesheet);
    graph->show();
}


void HistFrame::setHist(double ratio)
{
    length = static_cast<int>(ratio * oi->phist_label->h);
    graph->setGeometry(0,oi->phist_label->h - length,oi->phist_label->w,oi->phist_label->h);
    graph->update();
}

int  HistFrame::getLength()
{
    return length;
}
