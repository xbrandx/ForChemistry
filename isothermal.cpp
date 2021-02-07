#include "isothermal.h"

QString IsoThermal::PressureInput1;
QString IsoThermal::PressureInput2;
QString IsoThermal::VolumeInput1;
QString IsoThermal::VolumeInput2;
int IsoThermal::mole = 1;
double IsoThermal::temperature = 24;

IsoThermal::IsoThermal(QWidget *par)
    : parent(par)
{
    label[0] = new Label("- Isothermal", 180, 10, parent);
    label[1] = new Label("Mole #: ", 30, 45, parent);
    label[2] = new Label("Temperature (C): ", 190, 45, parent);
    label[3] = new Label("Enter Pressure 1 (atm): ", 30, 85, parent);
    label[4] = new Label("Enter Pressure 2 (atm): ", 30, 115, parent);
    label[5] = new Label("Enter Volume 1 (L): ", 30, 165, parent);
    label[6] = new Label("Enter Volume 2 (L): ", 30, 195, parent);
    QFont font1;
    font1.setPointSize(12);
    label[0]->setFont(font1);
    label[0]->setFixedWidth(130);
    label[0]->setFixedHeight(13);
    QFont font2;
    font2.setPointSize(8);
    for (int i = 1; i < 7; i++)
        label[i]->setFont(font2);
    label[3]->setFixedWidth(130);
    label[4]->setFixedWidth(130);

    line[0] = new LineEdit(160, 80, parent);
    line[1] = new LineEdit(160, 110, parent);
    line[2] = new LineEdit(160, 160, parent);
    line[3] = new LineEdit(160, 190, parent);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput1 = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput2 = d; });
    LineEdit::connect(line[2], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput1 = d; });
    LineEdit::connect(line[3], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput2 = d; });

    for (int i = 0; i < 2; i++)
        button[i] = new PushButton("Work Done", 310, 110+80*i, parent);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(); });

    combo = new ComboBox(10, 10, 80, 40, parent);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", parent);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

IsoThermal::~IsoThermal()
{
    Clear();
}

void IsoThermal::Clear()
{
    for (int i = 0; i < 7; i++)
    {
        delete label[i];
        label[i] = nullptr;
    }
    for (int i = 0; i < 4; i++)
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
