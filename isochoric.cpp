#include "isochoric.h"

Isochoric::Isochoric(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isochoric Process", 180, 10, 12, 150, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Enter Pressure (atm): ", 30, 85, 8, 130, par);
    label[4] = new Label("Enter Volume (L): ", 30, 125, 8, par);

    for (int i = 0; i < 2; i++)
        line[i] = new LineEdit(160, 80+40*i, par);

    button[0] = new PushButton("Work Done (w)", 160, 180, par);
    button[1] = new PushButton("Heat (q)", 160, 210, par);
    button[2] = new PushButton("ΔU", 250, 180, par);
    button[3] = new PushButton("ΔH", 340, 180, par);
    button[4] = new PushButton("ΔS", 250, 210, par);
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

    spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", par);
    DoubleSpinBox::connect(spin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

Isochoric::~Isochoric()
{
    Clear();
}

void Isochoric::Clear()
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
