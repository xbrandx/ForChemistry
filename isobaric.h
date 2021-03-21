#ifndef ISOBARIC_H
#define ISOBARIC_H

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
#include "math.h"

class Isobaric : public Formula
{
    Label *label[9];
    LineEdit *line[5];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin[2];
    QString PressureInput, InitialVolumeInput, FinalVolumeInput, CpInput, CvInput;
    int mole = 1;
    double InitialTemp = 24;
    double FinalTemp = 26;
public:
    Isobaric(QWidget *par);
    ~Isobaric();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOBARIC_H
