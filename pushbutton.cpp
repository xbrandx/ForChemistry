#include "pushbutton.h"
#include "idealgaslaw.h"

extern Formula *formula;

PushButton::PushButton(QString t,
                       int x, int y,
                       QWidget *par)
    : QPushButton(par)
{
    setText(t);
    move(x,y);
    formula->AddPushButton(this);
    show();
}

