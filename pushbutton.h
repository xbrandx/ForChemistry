#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include "formula.h"

class IdealGasLaw;

class PushButton : public QPushButton
{
public:
    PushButton(QString t, int x, int y, QWidget * par);
};

#endif // PUSHBUTTON_H
