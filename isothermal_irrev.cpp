#include "isothermal_irrev.h"

Isothermal_Irrev::Isothermal_Irrev(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isothermal Process (Irreversible)", 180, 10, 12, 250, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Enter Pressure (atm): ", 30, 75, 8, 130, par);
    label[4] = new Label("Enter Initnal Volume (L): ", 30, 110, 8, par);
    label[5] = new Label("Enter Final Volume (L): ", 30, 145, 8, par);

    for (int i = 0; i < 3; i++)
        line[i] = new LineEdit(160, 75+35*i, par);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ InitialVolumeInput = d; });
    LineEdit::connect(line[2], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ FinalVolumeInput = d; });

    button[0] = new PushButton("Work Done (w)", 25, 190, par);
    button[1] = new PushButton("Heat (q)", 110, 190, par);
    button[2] = new PushButton("ΔU", 190, 190, par);
    button[3] = new PushButton("ΔH", 270, 190, par);
    button[4] = new PushButton("ΔS", 350, 190, par);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateValue(true, false, false, false, false, par); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculateValue(false, true, false, false, false, par); });
    PushButton::connect(button[2], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, true, false, false, par); });
    PushButton::connect(button[3], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, false, true, false, par); });
    PushButton::connect(button[4], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, false, false, true, par); });

    combo = new ComboBox(10, 10, 80, 40, par);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", par);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ Temperature = d; });
}

Isothermal_Irrev::~Isothermal_Irrev()
{
    Clear();
}

void Isothermal_Irrev::Clear()
{
    for (int i = 0; i < 6; i++)
    {
        delete label[i];
        label[i] = nullptr;
    }
    for (int i = 0; i < 3; i++)
    {
        delete line[i];
        line[i] = nullptr;
    }
    for (int i = 0; i < 5; i++)
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

QString Isothermal_Irrev::FormulaName()
{
    return "Isothermal Process (Irreversible)";
}

void Isothermal_Irrev::CalculateValue(bool Work, bool Heat, bool DeltaU, bool DeltaH, bool DeltaS, QWidget *par)
{
    double heat, dS, work;
    double R = 8.314;
    double PressureValue = PressureInput.toDouble();
    double InitialVolumeValue = InitialVolumeInput.toDouble();
    double FinalVolumeValue = FinalVolumeInput.toDouble();
    bool PressureInputTest, InitialVolumeInputTest, FinalVolumeInputTest;
    double PressureInputf = InitialVolumeInput.toFloat(&PressureInputTest);
    double InitialVolumeInputf = InitialVolumeInput.toFloat(&InitialVolumeInputTest);
    double FinalVolumeInputf = FinalVolumeInput.toFloat(&FinalVolumeInputTest);

    if (PressureInputTest == false
            || InitialVolumeInputTest == false || FinalVolumeInputTest == false)
    {
        QMessageBox::about(par, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else if (InitialVolumeInputf <= 0.0f)
    {
        QMessageBox::about(par, "Error", "Initial Volume Value Need to be Greater Than 0.");
    } else if (Work) {
        work = -PressureValue*(FinalVolumeValue-InitialVolumeValue);
        QMessageBox::about(par, "Work Done", "The work done is " + QString::number(work) + " J.");
    } else if (Heat) {
        heat = PressureValue*(FinalVolumeValue-InitialVolumeValue);
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(heat) + " J.");
    } else if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (DeltaS) {
        dS = mole*R*log(FinalVolumeValue/InitialVolumeValue);
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(dS) + " J.");
    }
}
