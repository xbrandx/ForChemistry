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
private:
  /*std::unique_ptr<Label> label0;
    std::unique_ptr<Label> label1;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<LineEdit> line1;
    std::unique_ptr<LineEdit> line2;
    std::unique_ptr<PushButton> button1;
    std::unique_ptr<PushButton> button2;
    std::unique_ptr<ComboBox> combo;
    std::unique_ptr<DoubleSpinBox> spin;*/
};

#endif // IDEALGASLAW_H
