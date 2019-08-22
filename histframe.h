#ifndef HISTFRAME_H
#define HISTFRAME_H
#include <QFrame>
#include <QLabel>
#include "objectoutwardinfo.h"
#include <QMessageBox>

class HistFrame : public QFrame {
    Q_OBJECT
  public:
    HistFrame(QWidget * parent = nullptr);
    void setHist(double ratio);
    int getLength();
  private:
    QLabel * graph;
    ObjectOutwardInfo * oi;
    int length;

};

#endif // HISTFRAME_H
