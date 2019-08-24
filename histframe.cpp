#include "histframe.h"

HistFrame::HistFrame(QWidget * parent) : QFrame (parent)
{
    oi = new ObjectOutwardInfo();
    this->setGeometry(oi->phist_label->getRect());
    this->setStyleSheet(oi->hist_frame_stylesheet);

    length = 2;
    graph = new QLabel(this);
    graph->setGeometry(0,oi->phist_label->height() - length,oi->phist_label->width(),oi->phist_label->height());
    graph->setStyleSheet(oi->hist_stylesheet);
    graph->show();
}

void HistFrame::getSizeChanged()
{
    double ratio = static_cast<double>(length) / graph->height();
    length = static_cast<int>(ratio * this->height());
    graph->setGeometry(0,this->height() - length,this->width(),this->height());
    graph->update();
}

void HistFrame::setHist(double ratio)
{
    length = static_cast<int>(ratio * this->height());
    graph->setGeometry(0,this->height() - length,this->width(),this->height());
    graph->update();
}

int  HistFrame::getLength()
{
    return length;
}
