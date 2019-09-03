#include "histframe.h"

HistFrame::HistFrame(QWidget * parent) : QFrame (parent)
{
    oi = new ObjectOutwardInfo();
    this->setGeometry(oi->phist_label->getRect());
    this->setStyleSheet(oi->hist_frame_stylesheet);

    length = 2;
    graph = new QLabel(this);
    graph->setGeometry(0,oi->phist_label->height() - length,oi->phist_label->width(),length);
    graph->setStyleSheet(oi->hist_stylesheet);
    graph->show();
}

void HistFrame::getSizeChanged()
{
    length = static_cast<int>(ratio * this->height());
    graph->setGeometry(0,this->height() - length,this->width(),this->length);
    graph->update();
}

double HistFrame::getRatio(int len, int height)
{
    return static_cast<double>(len) / height + 0.5;
}

void HistFrame::setRatio(double r)
{
    ratio = r;
}

void HistFrame::setHist()
{
    length = static_cast<int>(ratio * this->height());
    graph->setGeometry(0,this->height() - length,this->width(),this->length);
    graph->update();
}

int  HistFrame::getLength()
{
    return length;
}
