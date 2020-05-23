#include "pushbutton.h"

PushButton::PushButton(QString s,
                       int x, int y,
                       QWidget *par)
    : QPushButton(par)
{
    setText(s);
    move(x,y);
    show();
}
