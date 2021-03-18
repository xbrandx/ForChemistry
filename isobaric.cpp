#include "isobaric.h"

Isobaric::Isobaric(QWidget *par)
    : Formula(par)
{
    label[0] = new Label("- Isobaric Process", 180, 10, 12, 150, 13, par);
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
    LineEdit::connect(line[0], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line[1], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ InitVolumeInput = d; });
    LineEdit::connect(line[2], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ FinalVolumeInput = d; });
    LineEdit::connect(line[3], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ CpInput = d; });
    LineEdit::connect(line[4], QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ CvInput = d; });

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
        spin[i] = new DoubleSpinBox(2, -273, 1000, 0.5, 24+2*i, 310, 40+30*i, " C", par);
    }
    DoubleSpinBox::connect(spin[0], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ init_temp = d; });
    DoubleSpinBox::connect(spin[1], QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ final_temp = d; });
}

Isobaric::~Isobaric()
{
    Clear();
}

void Isobaric::Clear()
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

QString Isobaric::FormulaName()
{
    return "Isobaric Process";
}

void Isobaric::CalculateValue(bool DeltaU, bool DeltaH, bool Heat, bool DeltaS, QWidget *par)
{
    double dU, dH, heat, dS, work;
    double R = 8.314;
    double PressureValue = PressureInput.toDouble();
    double InitVolumeValue = InitVolumeInput.toDouble();
    double FinalVolumeValue = FinalVolumeInput.toDouble();
    double CpValue = CpInput.toDouble();
    double CvValue = CvInput.toDouble();
    if (DeltaU) {
        dU = CvValue*(final_temp-init_temp);
        QMessageBox::about(par, "ΔU", "ΔU is " + QString::number(dU) + " J.");
    } else if (DeltaH) {
        dH = CpValue*(final_temp-init_temp);
        QMessageBox::about(par, "ΔH", "ΔH is " + QString::number(dH) + " J.");
    } else if (Heat){
        heat = CpValue*(final_temp-init_temp);
        QMessageBox::about(par, "Heat", "Heat is " + QString::number(heat) + " J.");
    } else if (DeltaS){
        dS = CpValue*log((final_temp+273)/(init_temp+273))+mole*R*log(FinalVolumeValue/InitVolumeValue);
        QMessageBox::about(par, "ΔS", "ΔS is " + QString::number(dS) + " J.");
    } else {
        work = -PressureValue * (FinalVolumeValue - InitVolumeValue);
        QMessageBox::about(par, "Work Done", "The work done is " + QString::number(work) + " J.");
    }
}
