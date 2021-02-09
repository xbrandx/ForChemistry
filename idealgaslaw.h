#ifndef IDEALGASLAW_H
#define IDEALGASLAW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
//#include <memory>
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"
#include "formula.h"

class IdealGasLaw : public Formula
{
    Label *label[5];
    LineEdit *line[2];
    PushButton *button[2];
    ComboBox *combo;
    DoubleSpinBox *spin;
public:
    static QString PressureInput, VolumeInput;
    static int mole;
    static double temperature;
    IdealGasLaw(QWidget *par);
    ~IdealGasLaw();
    void Clear();
    QString FormulaName();
    void CalculateVolume(QWidget *par);
    void CalculatePressure(QWidget *par);
};

#endif // IDEALGASLAW_H
