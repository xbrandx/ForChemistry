#include "pushbutton.h"
#include "idealgaslaw.h"

PushButton::PushButton(QString t,
                       int x, int y,
                       QWidget *par)
    : QPushButton(par)
{
    setText(t);
    move(x,y);
    show();
}

