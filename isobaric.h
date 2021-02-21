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

class Isobaric : public Formula
{
    Label *label[5];
    LineEdit *line[2];
    PushButton *button[5];
    ComboBox *combo;
    DoubleSpinBox *spin;
    QString PressureInput, VolumeInput;
    int mole = 1;
    double temperature = 24;
public:
    Isobaric(QWidget *par);
    ~Isobaric();
    void Clear();
    QString FormulaName();
    void CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par);
};

#endif // ISOBARIC_H
