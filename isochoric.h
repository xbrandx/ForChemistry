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
#include "math.h"

class Isochoric : public Formula
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
    Isochoric(QWidget *par);
    ~Isochoric();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOCHORIC_H
