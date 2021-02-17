#ifndef IDEALGASLAW_H
#define IDEALGASLAW_H

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

class IdealGasLaw : public Formula
{
    Label *label[5];
    LineEdit *line[2];
    PushButton *button[2];
    ComboBox *combo;
    DoubleSpinBox *spin;
    QString PressureInput, VolumeInput;
    int mole = 1;
    double temperature = 24;
public:
    IdealGasLaw(QWidget *par);
    ~IdealGasLaw();
    void Clear();
    QString FormulaName();
    void CalculateVolume(QWidget *par);
    void CalculatePressure(QWidget *par);
};

#endif // IDEALGASLAW_H
