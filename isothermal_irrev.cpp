#include "isothermal_irrev.h"

Isothermal_Irrev::Isothermal_Irrev(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isothermal Process (Irreversible)", 180, 10, 12, 250, 13, par);
    label[1] = new Label("Mole #: ", 30, 45, 8, par);
    label[2] = new Label("Initial Temperature (C): ", 190, 45, 8, par);
    label[3] = new Label("Final Temperature (C): ", 190, 75, 8, par);
    label[4] = new Label("Enter Cp: ", 30, 110, 8, par);
    label[5] = new Label("Enter Cv: ", 30, 145, 8, par);

    for (int i = 0; i < 2; i++)
        line[i] = new LineEdit(160, 110+35*i, par);
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ CpInput = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ CvInput = d; });

    button[0] = new PushButton("Work Done (w)", 25, 190, par);
    button[1] = new PushButton("Heat (q)", 110, 190, par);
    button[2] = new PushButton("ΔU", 190, 190, par);
    button[3] = new PushButton("ΔH", 270, 190, par);
    button[4] = new PushButton("ΔS", 350, 190, par);
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
        spin[i] = new DoubleSpinBox(2, -273, 1000, 0.5, 24+2*i, 310, 40+30*i, " C", par);
    }
    DoubleSpinBox::connect(spin[0], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ InitialTemp = d; });
    DoubleSpinBox::connect(spin[1], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ FinalTemp = d; });
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
    for (int i = 0; i < 2; i++)
    {
        delete spin[i];
        spin[i] = nullptr;
    }
    return;
}

QString Isothermal_Irrev::FormulaName()
{
    return "Isothermal Process (Irreversible)";
}

void Isothermal_Irrev::CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double dU, dH, heat, dS, work;
//    double R = 8.314;
    double CpValue = CpInput.toDouble();
    double CvValue = CvInput.toDouble();
    if (DeltaU) {
        dU = CvValue*(FinalTemp-InitialTemp);
        QMessageBox::about(par, "ΔU", "ΔU is " + QString::number(dU) + " J.");
    } else if (DeltaH) {
        dH = CpValue*(FinalTemp-InitialTemp);
        QMessageBox::about(par, "ΔH", "ΔH is " + QString::number(dH) + " J.");
    } else if (Heat){
        heat = CpValue*(FinalTemp-InitialTemp);
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(heat) + " J.");
    } else if (DeltaS){
        dS = CpValue*log((FinalTemp+273)/(InitialTemp+273));
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(dS) + " J.");
    } else {
        work = 0;
        QMessageBox::about(par, "Work Done", "The work done is " + QString::number(work) + " J.");
    }
}
