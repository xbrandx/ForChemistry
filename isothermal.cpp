#include "isothermal.h"

QString IsoThermal::PressureInput1;
QString IsoThermal::PressureInput2;
QString IsoThermal::VolumeInput1;
QString IsoThermal::VolumeInput2;
int IsoThermal::mole = 1;
double IsoThermal::temperature = 24;

Label * label10, * label11, * label12, * label13, * label14, * label15, * label16;
LineEdit * line11, * line12, * line13, * line14;
PushButton * button11, * button12;
ComboBox * combo11;
DoubleSpinBox * spin11;

IsoThermal::IsoThermal(QWidget *par)
    : parent(par)
{
    label10 = new Label("- Isothermal", 180, 10, parent);
    label11 = new Label("Mole #: ", 30, 45, parent);
    label12 = new Label("Temperature (C): ", 190, 45, parent);
    label13 = new Label("Enter Pressure 1 (atm): ", 30, 85, parent);
    label14 = new Label("Enter Pressure 2 (atm): ", 30, 115, parent);
    label15 = new Label("Enter Volume 1 (L): ", 30, 165, parent);
    label16 = new Label("Enter Volume 2 (L): ", 30, 195, parent);
    QFont font1;
    font1.setPointSize(12);
    label10->setFont(font1);
    label10->setFixedWidth(130);
    label10->setFixedHeight(13);
    QFont font2;
    font2.setPointSize(8);
    label11->setFont(font2);
    label12->setFont(font2);
    label13->setFont(font2);
    label13->setFixedWidth(130);
    label14->setFont(font2);
    label14->setFixedWidth(130);
    label15->setFont(font2);
    label16->setFont(font2);

    line11 = new LineEdit(160, 80, parent);
    line12 = new LineEdit(160, 110, parent);
    line13 = new LineEdit(160, 160, parent);
    line14 = new LineEdit(160, 190, parent);
    LineEdit::connect(line11, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput1 = d; });
    LineEdit::connect(line12, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput2 = d; });
    LineEdit::connect(line13, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput1 = d; });
    LineEdit::connect(line14, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput2 = d; });

    button11 = new PushButton("Work Done", 310, 110, parent);
    button12 = new PushButton("Work Done", 310, 190, parent);
    PushButton::connect(button11, &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(); });
    PushButton::connect(button12, &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(); });

    combo11 = new ComboBox(10, 10, 80, 40, parent);
    ComboBox::connect(combo11, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin11 = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", parent);
    DoubleSpinBox::connect(spin11, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

IsoThermal::~IsoThermal()
{
    Clear();
}

void IsoThermal::Clear()
{
    delete label10;
    label10 = nullptr;
    delete label11;
    label11 = nullptr;
    delete label12;
    label12 = nullptr;
    delete label13;
    label13 = nullptr;
    delete label14;
    label14 = nullptr;
    delete label15;
    label15 = nullptr;
    delete label16;
    label16 = nullptr;
    delete line11;
    line11 = nullptr;
    delete line12;
    line12 = nullptr;
    delete line13;
    line13 = nullptr;
    delete line14;
    line14 = nullptr;
    delete button11;
    button11 = nullptr;
    delete button12;
    button12 = nullptr;
    delete combo11;
    combo11 = nullptr;
    delete spin11;
    spin11 = nullptr;
    return;
}

QString IsoThermal::Name()
{
    return "Isothermal";
}

void IsoThermal::CalculateWorkFromPressure()
{
    double PressureValue1, PressureValue2, work;
    double R = 0.0821;
    double TempAdjust = temperature + 273;
    bool ok1, ok2;
    double d1 = PressureInput1.toFloat(&ok1);
    double d2 = PressureInput2.toFloat(&ok2);

    if (ok1 == false || ok2 == false)
    {
        QMessageBox::about(parent, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (d1 * d2 <= 0.0f)
    {
        QMessageBox::about(parent, "Error", "Pressure1/Pressure2 Needs to be Greater Than 0.");
    } else {
        PressureValue1 = PressureInput1.toDouble();
        PressureValue2 = PressureInput2.toDouble();
        work = -(mole*R*TempAdjust*log(PressureValue1/PressureValue2));
        QMessageBox::about(parent, "Work Done", "The isothermal work done is " + QString::number(work) + " J.");
    }
}

void IsoThermal::CalculateWorkFromVolume()
{
    double VolumeValue1, VolumeValue2, work;
    double R = 0.0821;
    double TempAdjust = temperature + 273;
    bool ok1, ok2;
    double d1 = VolumeInput1.toFloat(&ok1);
    double d2 = VolumeInput2.toFloat(&ok2);

    if (ok1 == false || ok2 == false)
    {
        QMessageBox::about(parent, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (d1 * d2 <= 0.0f)
    {
        QMessageBox::about(parent, "Error", "Volume2/Volume1 Needs to be Greater Than 0.");
    } else {
        VolumeValue1 = PressureInput1.toDouble();
        VolumeValue2 = PressureInput2.toDouble();
        work = -(mole*R*TempAdjust*log(VolumeValue2/VolumeValue1));
        QMessageBox::about(parent, "Work Done", "The isothermal work done is " + QString::number(work) + " J.");
    }
}
