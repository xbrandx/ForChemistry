#ifndef ISOTHERMAL_H
#define ISOTHERMAL_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
//#include <memory>
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"
#include "math.h"

class IsoThermal
{
public:
    QWidget * parent;
    static QString PressureInput1, PressureInput2, VolumeInput1, VolumeInput2;
    static int mole;
    static double temperature;
    IsoThermal(QWidget *par);
    ~IsoThermal();
    void Clear();
    QString Name();
    void CalculateWorkFromPressure();
    void CalculateWorkFromVolume();
};

#endif // ISOTHERMAL_H
