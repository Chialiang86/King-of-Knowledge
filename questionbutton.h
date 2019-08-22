#ifndef QUESTIONBUTTON_H
#define QUESTIONBUTTON_H
#include <QPushButton>
#include "objectoutwardinfo.h"

class QuestionButton : public QPushButton {
    Q_OBJECT
  public :
    QuestionButton(QWidget *parent);
    void setOption(const QString);
    void showTrueFalse();
    void done();
    void reset();
    bool trueOrFalse();
    bool getEnabled();

  private:
    bool isTrue;
    bool enabled;
    ObjectOutwardInfo * oi;

};

#endif // QUESTIONBUTTON_H
