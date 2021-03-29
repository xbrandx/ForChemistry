#ifndef ADIABATIC_H
#define ADIABATIC_H

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

class Adiabatic : public Formula
{
    Label *label[6];
    LineEdit *line[2];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin[2];
    QString CpInput, CvInput;
    int mole = 1;
    double InitialTemp = 24;
    double FinalTemp = 26;
public:
    Adiabatic(QWidget *par);
    ~Adiabatic();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool Work, bool Heat, bool DeltaU, bool DeltaH, bool DeltaS, QWidget *par);
};

#endif // ADIABATIC_H
