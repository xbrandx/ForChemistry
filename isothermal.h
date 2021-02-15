#ifndef ISOTHERMAL_H
#define ISOTHERMAL_H

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
#include "math.h"
#include "formula.h"

class IsoThermal : public Formula
{
    Label *label[9];
    LineEdit *line[4];
    PushButton *button[10];
    ComboBox *combo;
    DoubleSpinBox *spin;
public:
//    QWidget * parent;
    static QString PressureInput1, PressureInput2, VolumeInput1, VolumeInput2;
    static int mole;
    static double temperature;
    IsoThermal(QWidget *par);
    ~IsoThermal();
    void Clear();
    QString FormulaName();
    void CalculateWorkFromPressure(QWidget *par);
    void CalculateWorkFromVolume(QWidget *par);
};

#endif // ISOTHERMAL_H
