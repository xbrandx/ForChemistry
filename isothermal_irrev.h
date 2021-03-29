#ifndef ISOTHERMAL_IRREV_H
#define ISOTHERMAL_IRREV_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "formula.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"
#include "math.h"

class Isothermal_Irrev : public Formula
{
    Label *label[6];
    LineEdit *line[3];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin;
    QString PressureInput, InitialVolumeInput, FinalVolumeInput;
    int mole = 1;
    double Temperature = 24;
public:
    Isothermal_Irrev(QWidget *par);
    ~Isothermal_Irrev();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool Work, bool Heat, bool DeltaU, bool DeltaH, bool DeltaS, QWidget *par);
};

#endif // ISOTHERMAL_IRREV_H
