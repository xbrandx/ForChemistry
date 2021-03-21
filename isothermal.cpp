#include "isothermal.h"

Isothermal::Isothermal(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isothermal Process", 180, 10, 12, 150, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Enter Initial Pressure (atm): ", 30, 120, 8, 140, par);
    label[4] = new Label("Enter Final Pressure (atm): ", 30, 150, 8, 140, par);
    label[5] = new Label("Enter Intial Volume (L): ", 30, 265, 8, par);
    label[6] = new Label("Enter Final Volume (L): ", 30, 295, 8, par);
    label[7] = new Label("Method 1 (Using Pressure Values):", 30, 85, 10, 230, 20, par);
    label[8] = new Label("Method 2 (Using Volume Values):", 30, 230, 10, 230, 20, par);

    line[0] = new LineEdit(170, 120, par);
    line[1] = new LineEdit(170, 150, par);
    line[2] = new LineEdit(170, 265, par);
    line[3] = new LineEdit(170, 295, par);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ InitialPressureInput = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ FinalPressureInput = d; });
    LineEdit::connect(line[2], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ InitialVolumeInput = d; });
    LineEdit::connect(line[3], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ FinalVolumeInput = d; });

    for (int i = 0; i < 2; i++)
        button[i] = new PushButton("Work Done (w)", 28, 180+145*i, par);
    for (int i = 2; i < 4; i++)
        button[i] = new PushButton("Heat (q)", 110, 180+145*(i-2), par);
    for (int i = 4; i < 6; i++)
        button[i] = new PushButton("ΔU", 190, 180+145*(i-4), par);
    for (int i = 6; i < 8; i++)
        button[i] = new PushButton("ΔH", 270, 180+145*(i-6), par);
    for (int i = 8; i < 10; i++)
        button[i] = new PushButton("ΔS", 350, 180+145*(i-8), par);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateValueFromPressure(false, false, false, false, par); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculateValueFromVolume(false, false, false, false, par); });
    PushButton::connect(button[2], &QPushButton::clicked,
                        [=](){ CalculateValueFromPressure(false, false, true, false, par); });
    PushButton::connect(button[3], &QPushButton::clicked,
                        [=](){ CalculateValueFromVolume(false, false, true, false, par); });
    PushButton::connect(button[4], &QPushButton::clicked,
                        [=](){ CalculateValueFromPressure(true, false, false, false, par); });
    PushButton::connect(button[5], &QPushButton::clicked,
                        [=](){ CalculateValueFromVolume(true, false, false, false, par); });
    PushButton::connect(button[6], &QPushButton::clicked,
                        [=](){ CalculateValueFromPressure(false, true, false, false, par); });
    PushButton::connect(button[7], &QPushButton::clicked,
                        [=](){ CalculateValueFromVolume(false, true, false, false, par); });
    PushButton::connect(button[8], &QPushButton::clicked,
                        [=](){ CalculateValueFromPressure(false, false, false, true, par); });
    PushButton::connect(button[9], &QPushButton::clicked,
                        [=](){ CalculateValueFromVolume(false, false, false, true, par); });

    combo = new ComboBox(10, 10, 80, 40, par);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", par);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ Temp = d; });
}

Isothermal::~Isothermal()
{
    Clear();
}

void Isothermal::Clear()
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

QString Isothermal::FormulaName()
{
    return "Isothermal Process";
}

void Isothermal::CalculateValueFromPressure(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double InitialPressureValue, FinalPressureValue, work;
    double R = 0.0821;
    bool InitialPressureInputTest, FinalPressureInputTest;
    double InitialPressureInputf = InitialPressureInput.toFloat(&InitialPressureInputTest);
    double FinalPressureInputf = FinalPressureInput.toFloat(&FinalPressureInputTest);

    if (InitialPressureInputTest == true && FinalPressureInputTest == true
            && InitialPressureInputf > 0.0f
            && FinalPressureInputf > 0.0f)
    {
        InitialPressureValue = InitialPressureInput.toDouble();
        FinalPressureValue = FinalPressureInput.toDouble();
        work = mole*R*(Temp+273)*log(InitialPressureValue/FinalPressureValue);
    }

    if (InitialPressureInputTest == false || FinalPressureInputTest == false)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (InitialPressureInputf <= 0.0f || FinalPressureInputf <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Pressure Values Need to be Greater Than 0.");
    } else if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (Heat){
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(work) + " J.");
    } else if (DeltaS){
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(work) + " J.");
    } else {
        QMessageBox::about(par, "Work Done", "The isothermal work done is " + QString::number(-work) + " J.");
    }
}

void Isothermal::CalculateValueFromVolume(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double InitialVolumeValue, FinalVolumeValue, work;
    double R = 0.0821;
    bool InitialVolumeInputTest, FinalVolumeInputTest;
    double InitialVolumeInputf = InitialVolumeInput.toFloat(&InitialVolumeInputTest);
    double FinalVolumeInputf = FinalVolumeInput.toFloat(&FinalVolumeInputTest);

    if (InitialVolumeInputTest == true && FinalVolumeInputTest == true
            && InitialVolumeInputf > 0.0f
            && FinalVolumeInputf > 0.0f)
    {
        InitialVolumeValue = InitialVolumeInput.toDouble();
        FinalVolumeValue = FinalVolumeInput.toDouble();
        work = mole*R*(Temp+273)*log(FinalVolumeValue/InitialVolumeValue);
    }

    if (InitialVolumeInputTest == false || FinalVolumeInputTest == false)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (InitialVolumeInputf <= 0.0f || FinalVolumeInputf <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Volume Values Need to be Greater Than 0.");
    } else if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (Heat){
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(work) + " J.");
    } else if (DeltaS){
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(work) + " J.");
    } else {
        QMessageBox::about(par, "Work Done", "The isothermal work done is " + QString::number(-work) + " J.");
    }
}
