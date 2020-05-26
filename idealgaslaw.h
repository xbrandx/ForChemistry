#ifndef IDEALGASLAW_H
#define IDEALGASLAW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"

class IdealGasLaw
{
public:
    QWidget * parent;
    static QString PressureInput;
    static QString VolumeInput;
    static int mole;
    static double temperature;
    IdealGasLaw(QWidget *par);
    QString Name();
    void CalculateVolume();
    void CalculatePressure();
};

#endif // IDEALGASLAW_H
