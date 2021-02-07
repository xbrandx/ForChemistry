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

class IdealGasLaw
{
    Label *label[5];
    LineEdit *line[2];
    PushButton *button[2];
    ComboBox *combo;
    DoubleSpinBox *spin;
public:
    QWidget * parent;
    static QString PressureInput, VolumeInput;
    static int mole;
    static double temperature;
    IdealGasLaw(QWidget *par);
    ~IdealGasLaw();
    void Clear();
    QString Name();
    void CalculateVolume();
    void CalculatePressure();
};

#endif // IDEALGASLAW_H
