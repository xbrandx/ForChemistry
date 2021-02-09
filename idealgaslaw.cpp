#include "idealgaslaw.h"
#include <QDebug>

QString IdealGasLaw::PressureInput;
QString IdealGasLaw::VolumeInput;
int IdealGasLaw::mole = 1;
double IdealGasLaw::temperature = 24;

IdealGasLaw::IdealGasLaw(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Ideal Gas Law", 180, 10, par);
    label[1] = new Label("Mole #: ", 30, 45, par);
    label[2] = new Label("Temperature (C): ", 190, 45, par);
    label[3] = new Label("Enter Pressure (atm): ", 30, 85, par);
    label[4] = new Label("Enter Volume (L): ", 30, 125, par);
    QFont font1;
    font1.setPointSize(12);
    label[0]->setFont(font1);
    label[0]->setFixedWidth(130);
    label[0]->setFixedHeight(13);
    QFont font2;
    font2.setPointSize(8);
    for (int i = 1; i < 5; i++)
        label[i]->setFont(font2);
    label[3]->setFixedWidth(130);

    for (int i = 0; i < 2; i++)
        line[i] = new LineEdit(160, 80+40*i, par);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput = d; });

    button[0] = new PushButton("Find Volume  ", 310, 80, par);
    button[1] = new PushButton("Find Pressure", 310, 120, par);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateVolume(par); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculatePressure(par); });

    combo = new ComboBox(10, 10, 80, 40, par);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", par);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

IdealGasLaw::~IdealGasLaw()
{
    Clear();
}

void IdealGasLaw::Clear()
{
    for (int i = 0; i < 5; i++)
    {
        delete label[i];
        label[i] = nullptr;
    }
    for (int i = 0; i < 2; i++)
    {
        delete line[i];
        line[i] = nullptr;
    }
    for (int i = 0; i < 2; i++)
    {
        delete button[i];
        button[i] = nullptr;
    }
    delete combo;
    combo = nullptr;
    delete spin;
    spin = nullptr;
    return;
}

QString IdealGasLaw::FormulaName()
{
    return "Ideal Gas Law";
}

void IdealGasLaw::CalculateVolume(QWidget *par)
{
    double PressureValue, VolumeValue;
    double R = 0.0821;
    double TempAdjust = temperature + 273;

    if (PressureInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        PressureValue = PressureInput.toDouble();
        VolumeValue = (mole*R*TempAdjust)/PressureValue;
        QMessageBox::about(par, "Volume Value", "The volume is " + QString::number(VolumeValue) + " L.");
    }
}

void IdealGasLaw::CalculatePressure(QWidget *par)
{
    double PressureValue, VolumeValue;
    double R = 0.0821;
    double TempAdjust = temperature + 273;

    if (VolumeInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        VolumeValue = VolumeInput.toDouble();
        PressureValue = (mole*R*TempAdjust)/VolumeValue;
        QMessageBox::about(par, "Pressure Value", "The pressure is " + QString::number(PressureValue) + " atm.");
    }
}
