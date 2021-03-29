#ifndef ADIABATIC_IRREV_H
#define ADIABATIC_IRREV_H

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

class Adiabatic_Irrev : public Formula
{
    Label *label[8];
    LineEdit *line[4];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin[2];
    QString InitialVolumeInput, FinalVolumeInput, CpInput, CvInput;
    int mole = 1;
    double InitialTemp = 24;
    double FinalTemp = 26;
public:
    Adiabatic_Irrev(QWidget *par);
    ~Adiabatic_Irrev();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool Work, bool Heat, bool DeltaU, bool DeltaH, bool DeltaS, QWidget *par);
};

#endif // ADIABATIC_IRREV_H
