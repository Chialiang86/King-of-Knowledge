#ifndef CHOOSEPAGE_H
#define CHOOSEPAGE_H
#include <QPushButton>
#include <QLabel>
#include "objectoutwardinfo.h"

class ChoosePage : public QWidget
{
    Q_OBJECT
public:
    ChoosePage(QWidget * parent = nullptr);
    QLabel * logo_label;
    QPushButton * edit_btn;
    QPushButton * play_btn;
    QPushButton * player1_btn;
    QPushButton * player2_btn;
public slots:
    void chooseEdit();
    void choosePlay();
    void allDone();
signals:


private:
    ObjectOutwardInfo * oi;
};

#endif // CHOOSEPAGE_H
