#include "idealgaslaw.h"

QString IdealGasLaw::PressureInput;
QString IdealGasLaw::VolumeInput;
int IdealGasLaw::mole = 1;
double IdealGasLaw::temperature = 24;

IdealGasLaw::IdealGasLaw(QWidget *par)
    : parent(par)
{
    Label * label1 = new Label("Mole #: ", 30, 30, parent);
    Label * label2 = new Label("Temperature (C): ", 240, 30, parent);
    Label * label3 = new Label("Enter Pressure (atm): ", 30, 80, parent);
    Label * label4 = new Label("Enter Volume (L): ", 30, 120, parent);

    LineEdit * line1 = new LineEdit(180, 80, parent);
    LineEdit * line2 = new LineEdit(180, 120, parent);
    LineEdit::connect(line1, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line2, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput = d; });

    PushButton * button1 = new PushButton("Find Volume  ", "GasLaw_Volume", 350, 80, parent);
    PushButton * button2 = new PushButton("Find Pressure", "GasLaw_Pressure", 350, 120, parent);

    ComboBox * combo = new ComboBox(10, 10, 80, 30, parent);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    DoubleSpinBox * spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 350, 30, " C", parent);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d;});
}

QString IdealGasLaw::Name()
{
    return "Ideal Gas Law";
}

