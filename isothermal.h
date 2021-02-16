#ifndef ISOTHERMAL_H
#define ISOTHERMAL_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QDebug>
//#include <memory>
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"
#include "math.h"
#include "formula.h"

class IsoThermal : public Formula
{
    Label *label[9];
    LineEdit *line[4];
    PushButton *button[10];
    ComboBox *combo;
    DoubleSpinBox *spin;
    QString PressureInput1, PressureInput2, VolumeInput1, VolumeInput2;
    int mole = 1;
    double temperature = 24;
public:
    IsoThermal(QWidget *par);
    ~IsoThermal();
    void Clear();
    QString FormulaName();
    void CalculateWorkFromPressure(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
    void CalculateWorkFromVolume(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOTHERMAL_H
