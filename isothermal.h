#ifndef ISOTHERMAL_H
#define ISOTHERMAL_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QDebug>
//#include <memory>
#include "formula.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"
#include "math.h"

class Isothermal : public Formula
{
    Label *label[9];
    LineEdit *line[4];
    PushButton *button[10];
    ComboBox *combo;
    DoubleSpinBox *spin;
    QString InitialPressureInput, FinalPressureInput, InitialVolumeInput, FinalVolumeInput;
    int mole = 1;
    double Temp = 24;
public:
    Isothermal(QWidget *par);
    ~Isothermal();
    void Clear();
    QString FormulaName();
    void CalculateValueFromPressure(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
    void CalculateValueFromVolume(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOTHERMAL_H
