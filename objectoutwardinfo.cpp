#include "objectoutwardinfo.h"

ObjectOutwardInfo::ObjectOutwardInfo()
{

    button_stylesheet = "QPushButton{background-color:rgba(150,150,150,50%); color: rgb(90,250,250);\
            border-radius: 8px;  border: 3px groove rgb(120,120,120);}"
            "QPushButton:hover{background-color:white; color: black;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    true_stylesheet = "QPushButton{background-color:rgb(100,255,100); color: rgb(90,250,250);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    false_stylesheet = "QPushButton{background-color:rgb(255,100,100); color: rgb(90,250,250);\
            border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:pressed{background-color:rgb(140,140,140); border-style: inset; }";

    line_edit_stylesheet = "QLineEdit{color:rgb(90,250,250); background-color:rgba(150,150,150,50%);\
            border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    label_stylesheet = "QLabel{color:rgb(90,250,250); background-color:rgba(150,150,150,50%);\
            border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    dashboard_stylesheet  = "DashBoard{color:rgb(90,250,250); background-color:rgba(150,150,150,50%);\
            border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    hist_frame_stylesheet = "HistFrame{color:rgb(90,250,250); background-color:rgba(255,255,255,60%);\
            border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    hist_stylesheet = "QLabel{color:rgb(90,250,250); background-color:rgb(90,255,120);\
            border-radius: 8px;  border: 1px groove rgb(100,100,100);}";

    q_page_stylesheet = "Question{border-radius: 8px;  border: 1px groove rgb(100,100,100);}";


    background_img.load(":/picture/src/picture/main_view.png");
    menu_img.load(":/picture/src/picture/menu_view.png");

    textshow = new QFont("Courier",16);
    textinput = new QFont("Courier",16);
    message = new QFont("Courier",14);
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
    p_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px, 36);
    px = 48; py = py + p_label->height() + 12;
    phist_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px, 270);
    px = 12 ; py = py + phist_label->height() + 12;
    pscore_label = new PosSizeInfo(px,py,left_dashbord->width() - 2 * px,18);



    //q_page
    int wid = 336, hei = 328;
    q_page = new PosSizeInfo((main->w - wid) / 2,84,wid,hei);
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

    qDebug() << "p_label" ;
    p_label->setNewSize(wratio,hratio);
    qDebug() << "phist_label" ;
    phist_label->setNewSize(wratio,hratio);
    qDebug() << "pscore_label" ;
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

