#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>

class PushButton : public QPushButton
{
public:
    PushButton(QString s, int x, int y, QWidget * par);
};

#endif // PUSHBUTTON_H
