#include "isothermal.h"

IsoThermal::IsoThermal(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isothermal", 180, 10, 12, 130, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Enter Pressure 1 (atm): ", 30, 120, 8, 130, par);
    label[4] = new Label("Enter Pressure 2 (atm): ", 30, 150, 8, 130, par);
    label[5] = new Label("Enter Volume 1 (L): ", 30, 295, 8, par);
    label[6] = new Label("Enter Volume 2 (L): ", 30, 325, 8, par);
    label[7] = new Label("Method 1 (Using Pressure Values):", 30, 85, 10, 230, 20, par);
    label[8] = new Label("Method 2 (Using Volume Values):", 30, 260, 10, 230, 20, par);

    line[0] = new LineEdit(160, 120, par);
    line[1] = new LineEdit(160, 150, par);
    line[2] = new LineEdit(160, 295, par);
    line[3] = new LineEdit(160, 325, par);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput1 = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput2 = d; });
    LineEdit::connect(line[2], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput1 = d; });
    LineEdit::connect(line[3], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput2 = d; });

    for (int i = 0; i < 2; i++)
        button[i] = new PushButton("Work Done (w)", 160, 180+175*i, par);
    for (int i = 2; i < 4; i++)
        button[i] = new PushButton("Heat (q)", 160, 210+175*(i-2), par);
    for (int i = 4; i < 6; i++)
        button[i] = new PushButton("ΔU", 250, 180+175*(i-4), par);
    for (int i = 6; i < 8; i++)
        button[i] = new PushButton("ΔH", 340, 180+175*(i-6), par);
    for (int i = 8; i < 10; i++)
        button[i] = new PushButton("ΔS", 250, 210+175*(i-8), par);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(false, false, false, false, par); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(false, false, false, false, par); });
    PushButton::connect(button[2], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(false, false, true, false, par); });
    PushButton::connect(button[3], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(false, false, true, false, par); });
    PushButton::connect(button[4], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(true, false, false, false, par); });
    PushButton::connect(button[5], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(true, false, false, false, par); });
    PushButton::connect(button[6], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(false, true, false, false, par); });
    PushButton::connect(button[7], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(false, true, false, false, par); });
    PushButton::connect(button[8], &QPushButton::clicked,
                        [=](){ CalculateWorkFromPressure(false, false, false, true, par); });
    PushButton::connect(button[9], &QPushButton::clicked,
                        [=](){ CalculateWorkFromVolume(false, false, false, true, par); });

    combo = new ComboBox(10, 10, 80, 40, par);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", par);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

IsoThermal::~IsoThermal()
{
    Clear();
}

void IsoThermal::Clear()
{
    for (int i = 0; i < 9; i++)
    {
        delete label[i];
        label[i] = nullptr;
    }
    for (int i = 0; i < 4; i++)
    {
        delete line[i];
        line[i] = nullptr;
    }
    for (int i = 0; i < 10; i++)
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

QString IsoThermal::FormulaName()
{
    return "Isothermal";
}

void IsoThermal::CalculateWorkFromPressure(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double PressureValue1, PressureValue2, work;
    double R = 0.0821;
    double TempAdjust = temperature + 273;
    bool ok1, ok2;
    double d1 = PressureInput1.toFloat(&ok1);
    double d2 = PressureInput2.toFloat(&ok2);

    if (ok1 == false || ok2 == false)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (d1 * d2 <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Pressure1/Pressure2 Needs to be Greater Than 0.");
    } else if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (Heat){
        PressureValue1 = PressureInput1.toDouble();
        PressureValue2 = PressureInput2.toDouble();
        work = mole*R*TempAdjust*log(PressureValue1/PressureValue2);
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(work) + " J.");
    } else if (DeltaS){
        PressureValue1 = PressureInput1.toDouble();
        PressureValue2 = PressureInput2.toDouble();
        work = mole*R*TempAdjust*log(PressureValue1/PressureValue2);
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(work) + " J.");
    } else {
        PressureValue1 = PressureInput1.toDouble();
        PressureValue2 = PressureInput2.toDouble();
        work = -(mole*R*TempAdjust*log(PressureValue1/PressureValue2));
        QMessageBox::about(par, "Work Done", "The isothermal work done is " + QString::number(work) + " J.");
    }
}

void IsoThermal::CalculateWorkFromVolume(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double VolumeValue1, VolumeValue2, work;
    double R = 0.0821;
    double TempAdjust = temperature + 273;
    bool ok1, ok2;
    double d1 = VolumeInput1.toFloat(&ok1);
    double d2 = VolumeInput2.toFloat(&ok2);

    if (ok1 == false || ok2 == false)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (d1 * d2 <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Volume2/Volume1 Needs to be Greater Than 0.");
    } else if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (Heat){
        VolumeValue1 = PressureInput1.toDouble();
        VolumeValue2 = PressureInput2.toDouble();
        work = mole*R*TempAdjust*log(VolumeValue2/VolumeValue1);
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(work) + " J.");
    } else if (DeltaS){
        VolumeValue1 = PressureInput1.toDouble();
        VolumeValue2 = PressureInput2.toDouble();
        work = mole*R*TempAdjust*log(VolumeValue2/VolumeValue1);
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(work) + " J.");
    } else {
        VolumeValue1 = PressureInput1.toDouble();
        VolumeValue2 = PressureInput2.toDouble();
        work = -(mole*R*TempAdjust*log(VolumeValue2/VolumeValue1));
        QMessageBox::about(par, "Work Done", "The isothermal work done is " + QString::number(work) + " J.");
    }
}
