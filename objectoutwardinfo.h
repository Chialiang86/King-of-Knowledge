#ifndef OBJECTOUTWARDINFO_H
#define OBJECTOUTWARDINFO_H

#include <QSize>
#include <QPoint>
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QDebug>
#include <QRect>
#include "possize.h"


class ObjectOutwardInfo
{
public:
    ObjectOutwardInfo();
    void setMainwindowNewSize(int neww,int newh);
    void setDashboardNewSize(int neww,int newh);
    void setQPageNewSize(int neww,int newh);
    void setTimerShowNewSize(int neww,int newh);
    void setMainwindowNewSize(QSize new_size);
    double getXRatio(int oldw,int neww);
    double getYRatio(int oldh,int newh);
    int setFontPointSize(const QFont * f,double wratio);

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
    QString next_label_stylesheet;
    QString time_hist_green_stylesheet;
    QString time_hist_red_stylesheet;
    QString show_stylesheet;
    QString logo_stylesheet;

    QPixmap background_img;
    QPixmap menu_img;
    QPixmap next_img;
    QPixmap logo_img;

    //Choose page
    SizeInfo * choose;
    PosSizeInfo * loso_label;
    PosSizeInfo * edit_btn;
    PosSizeInfo * play_btn;
    PosSizeInfo * player1_btn;
    PosSizeInfo * player2_btn;

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
    PosSizeInfo * time_show_frame;

    PosSizeInfo * left_dashbord;
    PosSizeInfo * right_dashbord;

    PosSizeInfo * q_page;

    //time show
    PosSizeInfo * time_text_label;
    PosSizeInfo * time_hist_label;

    //player
    PosSizeInfo * p_label;
    PosSizeInfo * pscore_label;
    PosSizeInfo * phist_label;

    //q_page
    PosSizeInfo * q_label;
    PosSizeInfo * next_label;
    PosSizeInfo * a1_button;
    PosSizeInfo * a2_button;
    PosSizeInfo * a3_button;
    PosSizeInfo * a4_button;

};

#endif // OBJECTOUTWARDINFO_H
