#include "pushbutton.h"

#include <QDebug>

PushButton::PushButton(QString s,
                       int x, int y,
                       QWidget *par)
    : QPushButton(par)
{
    setText(s);
    move(x,y);
    show();
}

void PushButton::Click()
{
    click();

    qDebug() << "Click";
}
