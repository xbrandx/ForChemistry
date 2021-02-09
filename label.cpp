#include "label.h"

Label::Label(QString t,
             int x, int y,
             QWidget *par)
    : QLabel(par)
{
    setText(t);
    move(x,y);
    show();
}
