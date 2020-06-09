#include "idealgaslaw.h"
#include <QDebug>

QString IdealGasLaw::PressureInput;
QString IdealGasLaw::VolumeInput;
int IdealGasLaw::mole = 1;
double IdealGasLaw::temperature = 24;

Label * label0, * label1, * label2, * label3, * label4;
LineEdit * line1, * line2;
PushButton * button1, * button2;
ComboBox * combo1;
DoubleSpinBox * spin1;

IdealGasLaw::IdealGasLaw(QWidget *par)
    : parent(par)
    /*label0(new Label("- Ideal Gas Law", 180, 10, parent)),
      label1(new Label("Mole #: ", 30, 45, parent)),
      label2(new Label("Temperature (C): ", 190, 45, parent)),
      label3(new Label("Enter Pressure (atm): ", 30, 85, parent)),
      label4(new Label("Enter Volume (L): ", 30, 125, parent))
      line1(new LineEdit(160, 80, parent)),
      line2(new LineEdit(160, 120, parent))*/
{
    label0 = new Label("- Ideal Gas Law", 180, 10, parent);
    label1 = new Label("Mole #: ", 30, 45, parent);
    label2 = new Label("Temperature (C): ", 190, 45, parent);
    label3 = new Label("Enter Pressure (atm): ", 30, 85, parent);
    label4 = new Label("Enter Volume (L): ", 30, 125, parent);
    QFont font1;
    font1.setPointSize(12);
    label0->setFont(font1);
    label0->setFixedWidth(130);
    label0->setFixedHeight(13);
    QFont font2;
    font2.setPointSize(8);
    label1->setFont(font2);
    label2->setFont(font2);
    label3->setFont(font2);
    label3->setFixedWidth(130);
    label4->setFont(font2);

    line1 = new LineEdit(160, 80, parent);
    line2 = new LineEdit(160, 120, parent);
    LineEdit::connect(line1, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ PressureInput = d; });
    LineEdit::connect(line2, QOverload<const QString &>::of(&QLineEdit::textChanged),
                      [=](QString d){ VolumeInput = d; });

    button1 = new PushButton("Find Volume  ", 310, 80, parent);
    button2 = new PushButton("Find Pressure", 310, 120, parent);
    PushButton::connect(button1, &QPushButton::clicked,
                        [=](){ CalculateVolume(); });
    PushButton::connect(button2, &QPushButton::clicked,
                        [=](){ CalculatePressure(); });

    combo1 = new ComboBox(10, 10, 80, 40, parent);
    ComboBox::connect(combo1, QOverload<int>::of(&QComboBox::activated),
                      [=](int index){ mole = index + 1; });

    spin1 = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 310, 40, " C", parent);
    DoubleSpinBox::connect(spin1, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                      [=](double d){ temperature = d; });
}

IdealGasLaw::~IdealGasLaw()
{
    qDebug() << "dtor before";
    Clear();
    qDebug() << "dtor after";
}

void IdealGasLaw::Clear()
{
    delete label0;
    label0 = nullptr;
    delete label1;
    label1 = nullptr;
    delete label2;
    label2 = nullptr;
    delete label3;
    label3 = nullptr;
    delete label4;
    label4 = nullptr;
    delete line1;
    line1 = nullptr;
    delete line2;
    line2 = nullptr;
    delete button1;
    button1 = nullptr;
    delete button2;
    button2 = nullptr;
    delete combo1;
    combo1 = nullptr;
    delete spin1;
    spin1 = nullptr;
    return;
}

QString IdealGasLaw::Name()
{
    return "Ideal Gas Law";
}

void IdealGasLaw::CalculateVolume()
{
    double PressureValue, VolumeValue;
    double R = 0.0821;
    double TempAdjust = temperature + 273;

    if (PressureInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(parent, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        PressureValue = PressureInput.toDouble();
        VolumeValue = (mole*R*TempAdjust)/PressureValue;
        QMessageBox::about(parent, "Volume Value", "The volume is " + QString::number(VolumeValue) + " L.");
    }
}

void IdealGasLaw::CalculatePressure()
{
    double PressureValue, VolumeValue;
    double R = 0.0821;
    double TempAdjust = temperature + 273;

    if (VolumeInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(parent, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        VolumeValue = VolumeInput.toDouble();
        PressureValue = (mole*R*TempAdjust)/VolumeValue;
        QMessageBox::about(parent, "Pressure Value", "The pressure is " + QString::number(PressureValue) + " atm.");
    }
}
