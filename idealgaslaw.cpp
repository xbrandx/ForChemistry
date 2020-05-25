#include "idealgaslaw.h"

#include <QDebug>

QString IdealGasLaw::PressureInput;
QString IdealGasLaw::VolumeInput;
int IdealGasLaw::mole = 1;
double IdealGasLaw::temperature = 24;

IdealGasLaw::IdealGasLaw(QWidget *par)
    : parent(par)
{
    Label * label0 = new Label("- Ideal Gas Law", 180, 7, parent);
    Label * label1 = new Label("Mole #: ", 30, 42, parent);
    Label * label2 = new Label("Temperature (C): ", 190, 42, parent);
    Label * label3 = new Label("Enter Pressure (atm): ", 30, 82, parent);
    Label * label4 = new Label("Enter Volume (L): ", 30, 122, parent);
    QFont font;
    font.setPointSize(12);
    label0->setFont(font);
    label0->setFixedWidth(130);

    LineEdit * line1 = new LineEdit(160, 80, parent);
    LineEdit * line2 = new LineEdit(160, 120, parent);
    LineEdit::connect(line1, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line2, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput = d; });

    PushButton * button1 = new PushButton("Find Volume  ", "GasLaw_Volume", 310, 80, parent);
    PushButton * button2 = new PushButton("Find Pressure", "GasLaw_Pressure", 310, 120, parent);
    PushButton * button3 = new PushButton("test", "", 310, 140, parent);
    PushButton::connect(button3, &QPushButton::clicked,
                        [](){qDebug() << "Test";});     // this line of code doe snot work.

    ComboBox * combo = new ComboBox(10, 10, 80, 40, parent);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    DoubleSpinBox * spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", parent);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d;});
}

QString IdealGasLaw::Name()
{
    return "Ideal Gas Law";
}

