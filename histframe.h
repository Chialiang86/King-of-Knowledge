#ifndef HISTFRAME_H
#define HISTFRAME_H
#include <QFrame>
#include <QLabel>
#include "objectoutwardinfo.h"
#include <QMessageBox>

class HistFrame : public QFrame
{
    Q_OBJECT
public:
    HistFrame(QWidget * parent = nullptr);
    void setRatio(double);
    void setHist();
    void getSizeChanged();
    double getRatio(int,int);
    int getLength();
private:
    QLabel * graph;
    ObjectOutwardInfo * oi;
    double ratio;
    int length;

};

#endif // HISTFRAME_H
