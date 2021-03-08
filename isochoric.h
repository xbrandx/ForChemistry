#ifndef ISOCHORIC_H
#define ISOCHORIC_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "formula.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"

class Isochoric : public Formula
{
    Label *label[9];
    LineEdit *line[5];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin[2];
    QString PressureInput, InitVolumeInput, FinalVolumeInput, Cp, Cv;
    int mole = 1;
    double init_temp = 24;
    double final_temp = 24;
public:
    Isochoric(QWidget *par);
    ~Isochoric();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOCHORIC_H
