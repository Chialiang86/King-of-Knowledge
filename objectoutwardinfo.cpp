#include "objectoutwardinfo.h"

ObjectOutwardInfo::ObjectOutwardInfo()
{

    button_stylesheet = "QPushButton{background-color:rgb(100,100,100); color: rgb(90,200,200);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:hover{background-color:white; color: black;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    true_stylesheet = "QPushButton{background-color:rgb(100,255,100); color: rgb(90,200,200);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    false_stylesheet = "QPushButton{background-color:rgb(255,100,100); color: rgb(90,200,200);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    line_edit_stylesheet = "QLineEdit{color:rgb(90,200,200); background-color:rgb(100,100,100);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}";

    label_stylesheet = "QLabel{color:rgb(90,200,200); background-color:rgb(90,90,90);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}";

    dashboard_stylesheet = "DashBoard{color:rgb(90,200,200); background-color:rgb(90,90,90);\
            border-radius: 8px;  border: 1px groove gray;}";
    hist_frame_stylesheet = "HistFrame{color:rgb(90,200,200); background-color:rgb(120,120,120);\
            border-radius: 8px;  border: 1px groove gray;}";

    hist_stylesheet = "QLabel{color:rgb(90,200,200); background-color:rgb(90,255,90);\
            border-radius: 8px;  border: 1px groove gray;}";

    q_page_stylesheet = "Question{border-radius: 8px;  border: 1px groove gray; border-style: outset;}";

    textshow = new QFont("Courier",12);
    textinput = new QFont("Courier",15);
    message = new QFont("Courier",12);
    next = new QFont("Courier",27);
    textshow_color = new QColor(150,235,255);
    textinput_color = new QColor(150,235,255);
    button_color = new QColor(100,100,100);

    //menu info
    menu = new SizeInfo(500,580);
    pname_guide = new PosSizeInfo(50,40,400,50);
    pname = new PosSizeInfo(130,110,240,80);
    ip_guide = new PosSizeInfo(50,210,400,50);
    ip = new PosSizeInfo(130,280,240,80);
    start_guide = new PosSizeInfo(50,380,400,50);
    start = new PosSizeInfo(130,450,240,80);

    //main info
    main = new SizeInfo(600,450);
    int px, py;
    int d_w ,d_h;

    //dashboard
    d_w = 108; d_h = 372;
    left_dashbord = new PosSizeInfo(12,40,d_w,d_h);
    right_dashbord = new PosSizeInfo(480,40,d_w,d_h);

    px = 12; py = 12;
    p_label = new PosSizeInfo(px,py,left_dashbord->w - 2 * px, 36);
    px = 48; py = py + p_label->h + 12;
    phist_label = new PosSizeInfo(px,py,left_dashbord->w - 2 * px, 270);
    px = 12 ; py = py + phist_label->h + 12;
    pscore_label = new PosSizeInfo(px,py,left_dashbord->w - 2 * px,18);



    //q_page
    int wid = 336, hei = 328;
    q_page = new PosSizeInfo((main->w - wid) / 2,84,wid,hei);
    px = 12; py = 36;
    next_label = new PosSizeInfo(px, py, q_page->w - 2 * px ,q_page->h - 2 * py);
    px = 12; py = 24;
    q_label = new PosSizeInfo(px,py,q_page->w - 2 * px,54);
    px = 48;
    py = q_label->y  + q_label->h + 24;
    const int py_const = py;
    a1_button = new PosSizeInfo(px, py,q_page->w - 2 * px,(q_page->h - py_const - 12) / 4 - 12);
    py = a1_button->y + a1_button->h + 12;
    a2_button = new PosSizeInfo(px, py,q_page->w - 2 * px,(q_page->h - py_const - 12) / 4 - 12);
    py = a2_button->y + a2_button->h + 12;
    a3_button = new PosSizeInfo(px, py,q_page->w - 2 * px,(q_page->h - py_const - 12) / 4 - 12);
    py = a3_button->y + a3_button->h + 12;
    a4_button = new PosSizeInfo(px, py,q_page->w - 2 * px,(q_page->h - py_const - 12) / 4 - 12);
}
