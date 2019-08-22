#ifndef OBJECTOUTWARDINFO_H
#define OBJECTOUTWARDINFO_H

#include <QSize>
#include <QPoint>
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QDebug>
#include "possize.h"

class ObjectOutwardInfo
{
public:
    ObjectOutwardInfo();

    QFont * textshow;
    QFont * textinput;
    QFont * message;
    QFont * next;
    QColor * textshow_color;
    QColor * textinput_color;
    QColor * button_color;
    QString button_stylesheet;
    QString true_stylesheet;
    QString false_stylesheet;
    QString line_edit_stylesheet;
    QString label_stylesheet;
    QString hist_stylesheet;
    QString q_page_stylesheet;
    QString dashboard_stylesheet;
    QString hist_frame_stylesheet;

    //menu page
    SizeInfo * menu;
    PosSizeInfo * pname_guide;
    PosSizeInfo * pname;
    PosSizeInfo * ip_guide;
    PosSizeInfo * ip;
    PosSizeInfo * start_guide;
    PosSizeInfo * start;


    //main page
    SizeInfo * main;


    PosSizeInfo * pk_label;
    PosSizeInfo * timer_label;

    //player
    PosSizeInfo * left_dashbord;
    PosSizeInfo * right_dashbord;
    PosSizeInfo * p_label;
    PosSizeInfo * pscore_label;
    PosSizeInfo * phist_label;



    //q_page
    PosSizeInfo * q_page;
    PosSizeInfo * q_label;
    PosSizeInfo * next_label;
    PosSizeInfo * a1_button;
    PosSizeInfo * a2_button;
    PosSizeInfo * a3_button;
    PosSizeInfo * a4_button;

};

#endif // OBJECTOUTWARDINFO_H
