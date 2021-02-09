#include "label.h"

extern Formula *formula;

Label::Label(QString t,
             int x, int y,
             QWidget *par)
    : QLabel(par)
{
    qDebug() << "3.5?";
    setText(t);
    move(x,y);
    formula->AddLabel(this);
    qDebug() << "3.7?";
    show();
}
