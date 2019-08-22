#ifndef POSSIZE_H
#define POSSIZE_H

class SizeInfo {
  public :
    SizeInfo();
    SizeInfo(int w_ = 0,int h_ = 0) {
        w = w_;
        h = h_;
    }
    int w;
    int h;
};

class PosInfo {
  public :
    PosInfo();
    PosInfo(int x_ = 0,int y_ = 0) {
        x = x_;
        y = y_;
    }
    int x;
    int y;
};

class PosSizeInfo {
  public :
    PosSizeInfo();
    PosSizeInfo(int x_ = 0,int y_ = 0,int w_ = 0,int h_ = 0) {
        x = x_;
        y = y_;
        w = w_;
        h = h_;
    }
    int x;
    int y;
    int w;
    int h;
};

#endif // POSSIZE_H
