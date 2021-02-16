#include "label.h"

Label::Label(QString t, int x, int y, int f, QWidget *par)
    : QLabel(par)
{
    setText(t);
    move(x,y);
    font.setPointSize(f);
    setFont(font);
    show();
}

Label::Label(QString t, int x, int y, int f, int w, QWidget *par)
    : QLabel(par)
{
    setText(t);
    move(x,y);
    font.setPointSize(f);
    setFont(font);
    setFixedWidth(w);
    show();
}

Label::Label(QString t, int x, int y, int f, int w, int h, QWidget *par)
    : QLabel(par)
{
    setText(t);
    move(x,y);
    font.setPointSize(f);
    setFont(font);
    setFixedWidth(w);
    setFixedHeight(h);
    show();
}
