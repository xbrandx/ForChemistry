#include "label.h"

Label::Label(QString s,
             int x, int y,
             QWidget *par)
    : QLabel(par)
{
    setText(s);
    move(x,y);
    show();
}
