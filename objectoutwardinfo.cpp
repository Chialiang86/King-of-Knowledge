#include "objectoutwardinfo.h"

ObjectOutwardInfo::ObjectOutwardInfo()
{

    button_stylesheet = "QPushButton{background-color:rgba(150,150,150,50%); color: rgb(160,238,225);\
            border-radius: 8px;  border: 3px groove rgb(120,120,120);}"
            "QPushButton:hover{background-color:white; color: black;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    true_stylesheet = "QPushButton{background-color:rgb(190,237,199); color: white;\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    false_stylesheet = "QPushButton{background-color:rgb(244,96,108); color: white;\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    line_edit_stylesheet = "QLineEdit{color:rgb(160,238,225); background-color:rgba(150,150,150,50%);\
            border-radius: 8px;  border: 1px groove rgb(112,128,144);}";

    label_stylesheet = "QLabel{color:rgb(160,238,225); background-color:rgba(150,150,150,50%);\
            border-radius: 8px;  border: 1px groove rgb(112,128,144);}";

    dashboard_stylesheet  = "DashBoard{border-image: url(:/picture/src/picture/dash_04.jpg) 0 0 0 0 stretch stretch;\
            border-radius: 10px;  border: 2px groove rgb(112,128,144);}";

    hist_frame_stylesheet = "HistFrame{color:rgb(160,238,225); background-color:rgba(255,255,255,60%);\
            border-radius: 8px;  border: 1px groove rgb(112,128,144);}";

    hist_stylesheet = "QLabel{color:rgb(160,238,225); background-color:rgb(190,237,199);\
            border-radius: 8px;  border: 1px groove rgb(112,128,144);}";

    q_page_stylesheet = "Question{border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    next_label_stylesheet = "QLabel{border-radius: 12px;  border: 2px groove rgb(150,150,150);}";

    time_hist_green_stylesheet = "QLabel{color:rgb(160,238,225); background-color:rgb(190,237,199);\
            border-radius: 3px;}";

    time_hist_red_stylesheet = "QLabel{color:rgb(160,238,225); background-color:rgb(244,96,108);\
            border-radius: 3px;}";

    show_stylesheet = "QLabel{color:rgb(235,235,235);}";

    logo_stylesheet = "QLabel{border-image: url(:/picture/src/picture/logo.png) 0 0 0 0 stretch stretch;}";

    background_img.load(":/picture/src/picture/main_view.png");
    menu_img.load(":/picture/src/picture/menu_view.png");
    logo_img.load(":/picture/src/picture/logo.png");

    textshow = new QFont("Courier",16);
    textinput = new QFont("Courier",16);
    message = new QFont("Courier",14);
    next = new QFont("Courier",27);

    textshow_color = new QColor(150,235,255);
    textinput_color = new QColor(150,235,255);
    button_color = new QColor(100,100,100);

    //choose info
    choose = new SizeInfo(400,400);
    loso_label = new PosSizeInfo(100,50,200,50);
    edit_btn = new PosSizeInfo(50,150,300,80);
    play_btn = new PosSizeInfo(50,270,300,80);
    player1_btn = new PosSizeInfo(50,150,300,80);
    player2_btn = new PosSizeInfo(50,270,300,80);

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
    int q_y = 84;
    int px, py;
    int t_w, t_h;
    int d_w ,d_h;
    int wid ,hei;

    //time show
    t_w = 336; t_h = 60;
    px = (main->w - t_w) / 2; py = (q_y - t_h) / 2;
    time_show_frame = new PosSizeInfo(px, py, t_w, t_h);
    t_w = 280; t_h = 10;
    time_hist_label = new PosSizeInfo((time_show_frame->width() - t_w) / 2, time_show_frame->height() - 12, t_w, t_h);
    t_w = 300; t_h = 30;
    px = (time_show_frame->width() - t_w) / 2;
    py = 8;
    time_text_label = new PosSizeInfo(px, py, t_w, t_h);

    //dashboard
    d_w = 108; d_h = 372;
    left_dashbord = new PosSizeInfo(12,40,d_w,d_h);
    right_dashbord = new PosSizeInfo(480,40,d_w,d_h);

    px = 12; py = 12;
    p_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px, 36);
    px = 48; py = py + p_label->height() + 12;
    phist_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px, 270);
    px = 12 ; py = py + phist_label->height() + 12;
    pscore_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px,18);

    //q_page
    wid = 336; hei = 328;
    q_page = new PosSizeInfo((main->w - wid) / 2,q_y,wid,hei);
    px = 12; py = 36;
    next_label = new PosSizeInfo(px, py, q_page->width() - 2 * px ,q_page->height() - 2 * py);
    px = 12; py = 24;
    q_label = new PosSizeInfo(px,py,q_page->width() - 2 * px,54);
    px = 48;
    py = q_label->y()  + q_label->height() + 24;
    const int py_const = py;
    a1_button = new PosSizeInfo(px, py,q_page->width() - 2 * px,(q_page->height() - py_const - 12) / 4 - 12);
    py = a1_button->y() + a1_button->height() + 12;
    a2_button = new PosSizeInfo(px, py,q_page->width() - 2 * px,(q_page->height() - py_const - 12) / 4 - 12);
    py = a2_button->y() + a2_button->height() + 12;
    a3_button = new PosSizeInfo(px, py,q_page->width() - 2 * px,(q_page->height() - py_const - 12) / 4 - 12);
    py = a3_button->y() + a3_button->height() + 12;
    a4_button = new PosSizeInfo(px, py,q_page->width() - 2 * px,(q_page->height() - py_const - 12) / 4 - 12);
}
double ObjectOutwardInfo::getXRatio(int oldw,int neww)
{
        return static_cast<double>(neww) / oldw;
}

double ObjectOutwardInfo::getYRatio(int oldh,int newh)
{
    return static_cast<double>(newh) / oldh;
}
void ObjectOutwardInfo::setMainwindowNewSize(int neww,int newh)
{
    double wratio = static_cast<double>(neww) / main->w;
    double hratio = static_cast<double>(newh) / main->h;
    textshow->setPointSize(setFontPointSize(textshow,wratio));
    textinput->setPointSize(setFontPointSize(textinput,wratio));
    message->setPointSize(setFontPointSize(message,wratio));
    next->setPointSize(setFontPointSize(next,wratio));

    main->w = neww; main->h = newh;
    left_dashbord->setNewSize(wratio,hratio);
    right_dashbord->setNewSize(wratio,hratio);
    q_page->setNewSize(wratio,hratio);
    time_show_frame->setNewSize(wratio,hratio);
}


void ObjectOutwardInfo::setDashboardNewSize(int neww,int newh)
{
    double wratio = static_cast<double>(neww) / main->w;
    double hratio = static_cast<double>(newh) / main->h;

    main->w = neww; main->h = newh;
    textshow->setPointSize(setFontPointSize(textshow,wratio));
    textinput->setPointSize(setFontPointSize(textinput,wratio));
    message->setPointSize(setFontPointSize(message,wratio));
    next->setPointSize(setFontPointSize(next,wratio));

    p_label->setNewSize(wratio,hratio);
    phist_label->setNewSize(wratio,hratio);
    pscore_label->setNewSize(wratio,hratio);

}

void ObjectOutwardInfo::setQPageNewSize(int neww,int newh)
{
    double wratio = static_cast<double>(neww) / main->w;
    double hratio = static_cast<double>(newh) / main->h;

    main->w = neww; main->h = newh;
    textshow->setPointSize(setFontPointSize(textshow,wratio));
    textinput->setPointSize(setFontPointSize(textinput,wratio));
    message->setPointSize(setFontPointSize(message,wratio));
    next->setPointSize(setFontPointSize(next,wratio));

    next_label->setNewSize(wratio,hratio);
    q_label->setNewSize(wratio,hratio);
    a1_button->setNewSize(wratio,hratio);
    a2_button->setNewSize(wratio,hratio);
    a3_button->setNewSize(wratio,hratio);
    a4_button->setNewSize(wratio,hratio);
}

void ObjectOutwardInfo::setTimerShowNewSize(int neww,int newh)
{
    double wratio = static_cast<double>(neww) / main->w;
    double hratio = static_cast<double>(newh) / main->h;
    textshow->setPointSize(setFontPointSize(textshow,wratio));
    textinput->setPointSize(setFontPointSize(textinput,wratio));
    message->setPointSize(setFontPointSize(message,wratio));
    next->setPointSize(setFontPointSize(next,wratio));

    main->w = neww; main->h = newh;
    time_hist_label->setNewSize(wratio,hratio);
    time_text_label->setNewSize(wratio,hratio);

}

void ObjectOutwardInfo::setMainwindowNewSize(QSize new_size)
{
    double wratio = static_cast<double>(new_size.width())  / main->w;
    double hratio = static_cast<double>(new_size.height()) / main->h;
    textshow->setPointSize(setFontPointSize(textshow,wratio));
    textinput->setPointSize(setFontPointSize(textinput,wratio));
    message->setPointSize(setFontPointSize(message,wratio));
    next->setPointSize(setFontPointSize(next,wratio));

    main->w = new_size.width(); main->h = new_size.height();

    left_dashbord->setNewSize(wratio,hratio);
    right_dashbord->setNewSize(wratio,hratio);
    q_page->setNewSize(wratio,hratio);

    p_label->setNewSize(wratio,hratio);
    phist_label->setNewSize(wratio,hratio);
    pscore_label->setNewSize(wratio,hratio);

    next_label->setNewSize(wratio,hratio);
    q_label->setNewSize(wratio,hratio);
    a1_button->setNewSize(wratio,hratio);
    a2_button->setNewSize(wratio,hratio);
    a3_button->setNewSize(wratio,hratio);
    a4_button->setNewSize(wratio,hratio);
}


int ObjectOutwardInfo::setFontPointSize(const QFont * f,double wratio)
{
    double new_size = static_cast<double>(f->pointSize()) * wratio;
    return static_cast<int>(new_size + 0.5);
}

