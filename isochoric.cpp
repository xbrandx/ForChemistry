#include "isochoric.h"

Isochoric::Isochoric(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isochoric Process", 180, 10, 12, 150, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Initial Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Final Temperature (C): ", 190, 75, 8, par);
    label[4] = new Label("Enter Pressure (atm): ", 30, 110, 8, 130, par);
    label[5] = new Label("Enter Initnal Volume (L): ", 30, 145, 8, par);
    label[6] = new Label("Enter Final Volume (L): ", 30, 180, 8, par);
    label[7] = new Label("Enter Cp: ", 30, 215, 8, par);
    label[8] = new Label("Enter Cv: ", 30, 250, 8, par);

    for (int i = 0; i < 5; i++)
        line[i] = new LineEdit(160, 110+35*i, par);

    button[0] = new PushButton("Work Done (w)", 25, 290, par);
    button[1] = new PushButton("Heat (q)", 110, 290, par);
    button[2] = new PushButton("ΔU", 190, 290, par);
    button[3] = new PushButton("ΔH", 270, 290, par);
    button[4] = new PushButton("ΔS", 350, 290, par);
    PushButton::connect(button[0], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, false, false, par); });
    PushButton::connect(button[1], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, true, false, par); });
    PushButton::connect(button[2], &QPushButton::clicked,
                        [=](){ CalculateValue(true, false, false, false, par); });
    PushButton::connect(button[3], &QPushButton::clicked,
                        [=](){ CalculateValue(false, true, false, false, par); });
    PushButton::connect(button[4], &QPushButton::clicked,
                        [=](){ CalculateValue(false, false, false, true, par); });

    combo = new ComboBox(10, 10, 80, 40, par);
    ComboBox::connect(combo, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    for (int i = 0; i < 2; i++)
    {
        spin[i] = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40+30*i, " C", par);
    }
    DoubleSpinBox::connect(spin[0], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ init_temp = d; });
    DoubleSpinBox::connect(spin[1], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ final_temp = d; });
}

Isochoric::~Isochoric()
{
    Clear();
}

void Isochoric::Clear()
{
    for (int i = 0; i < 9; i++)
    {
        delete label[i];
        label[i] = nullptr;
    }
    for (int i = 0; i < 5; i++)
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
    for (int i = 0; i < 2; i++)
    {
        delete spin[i];
        spin[i] = nullptr;
    }
    return;
}

QString Isochoric::FormulaName()
{
    return "Isochoric Process";
}

void Isochoric::CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    if (DeltaU) {
        QMessageBox::about(par, "ΔU", "ΔU is 0 J.");
    } else if (DeltaH) {
        QMessageBox::about(par, "ΔH", "ΔH is 0 J.");
    } else if (Heat){
        QMessageBox::about(par, "Heat", "Heat is 0 J.");
    } else if (DeltaS){
        QMessageBox::about(par, "ΔS", "ΔS is 0 J.");
    } else {
        QMessageBox::about(par, "Work Done", "The work done is 0 J.");
    }
}
