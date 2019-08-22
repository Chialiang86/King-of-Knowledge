#include "questionbutton.h"

QuestionButton::QuestionButton(QWidget * parent) : QPushButton(parent) {
    oi = new ObjectOutwardInfo();
    this->setStyleSheet(oi->button_stylesheet);
    this->setFont(*oi->textshow);
    isTrue = false;
}

void QuestionButton::reset() {
    isTrue = false;
    enabled = true;
    this->setStyleSheet(oi->button_stylesheet);
    this->setText("");
    this->hide();
}

void QuestionButton::setOption(const QString str) {
    isTrue = str.split("..").at(0) == "o" ? true : false;
    this->setText(str.split("..").at(1));
    this->update();
}

bool QuestionButton::trueOrFalse() {
    return isTrue;
}

void QuestionButton::showTrueFalse() {
    if(isTrue)
        this->setStyleSheet(oi->true_stylesheet);
    else
        this->setStyleSheet(oi->false_stylesheet);
}

void QuestionButton::done() {
    enabled = false;
}

bool QuestionButton::getEnabled() {
    return enabled;
}
