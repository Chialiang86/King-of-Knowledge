#ifndef POSSIZE_H
#define POSSIZE_H
#include <QRect>
#include <QDebug>

class SizeInfo
{
public :
    SizeInfo();
    SizeInfo(int w_ = 0,int h_ = 0){
        w = w_;
        h = h_;
    }
    int w;
    int h;
};

class PosInfo
{
public :
    PosInfo();
    PosInfo(int x_ = 0,int y_ = 0){
        x = x_;
        y = y_;
    }
    int x;
    int y;
};

class PosSizeInfo : public QRect
{
public :
    PosSizeInfo();
    PosSizeInfo(int x_ = 0,int y_ = 0,int w_ = 0,int h_ = 0){
        this->setX(x_);
        this->setY(y_);
        this->setWidth(w_);
        this->setHeight(h_);
    }

    QRect getRect(){
        return *this;
    }

    void setNewSize(double wratio,double hratio){

        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
    }

    void setNewSize(QSize old_,QSize new_){
        double wratio = static_cast<double>(new_.width()) / old_.width();
        double hratio = static_cast<double>(new_.height()) / old_.height();

        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
    }

    void setNewSize(int oldw,int oldh,int neww,int newh){
        double wratio = static_cast<double>(neww) / oldw;
        double hratio = static_cast<double>(newh) / oldh;
        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
    }

    QRect getNewSize(double wratio,double hratio){
        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
        return *this;
    }

    QRect getNewSize(QSize old_,QSize new_){
        double wratio = static_cast<double>(new_.width()) / old_.width();
        double hratio = static_cast<double>(new_.height()) / old_.height();
        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
        return *this;
    }

    QRect getNewSize(int oldw,int oldh,int neww,int newh){
        double wratio = static_cast<double>(neww) / oldw;
        double hratio = static_cast<double>(newh) / oldh;
        int x = this->x();
        int y = this->y();
        int w = this->width();
        int h = this->height();
        this->setX(static_cast<int>(wratio * x + 0.5));
        this->setY(static_cast<int>(hratio * y + 0.5));
        this->setWidth(static_cast<int>(wratio * w + 0.5));
        this->setHeight(static_cast<int>(hratio * h + 0.5));
        return *this;
    }
};

#endif // POSSIZE_H
