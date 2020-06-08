#ifndef ISOTHERMAL_H
#define ISOTHERMAL_H

#include <QObject>
#include <QWidget>
#include <QString>
#include "label.h"

class IsoThermal
{
public:
    QWidget * parent;
    IsoThermal(QWidget *par);
    ~IsoThermal();
    void Clear();
    QString Name();
};

#endif // ISOTHERMAL_H
