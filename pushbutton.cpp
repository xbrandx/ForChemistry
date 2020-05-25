#include "pushbutton.h"
#include "idealgaslaw.h"

PushButton::PushButton(QString t, QString p,
                       int x, int y,
                       QWidget *par)
    : QPushButton(par)
{
    setText(t);
    move(x,y);
    program = p;
    show();
}

void PushButton::mousePressEvent(QMouseEvent * ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        if (program == "GasLaw_Volume")
        {
            GasLaw_Volume();
        } else if (program == "GasLaw_Pressure")
        {
            GasLaw_Pressure();
        }
    }
}

void PushButton::GasLaw_Volume()
{
    double PressureValue;
    double VolumeValue;
    double R = 0.0821;
    double TempAdjust = IdealGasLaw::temperature + 273;

    if (IdealGasLaw::PressureInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(this, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        PressureValue = std::stod(IdealGasLaw::PressureInput.toStdString());
        VolumeValue = (IdealGasLaw::mole*R*TempAdjust)/PressureValue;
        QMessageBox::about(this, "Volume Value", "The volume is " + QString::number(VolumeValue) + " L.");
    }
}

void PushButton::GasLaw_Pressure()
{
    double PressureValue;
    double VolumeValue;
    double R = 0.0821;
    double TempAdjust = IdealGasLaw::temperature + 273;

    if (IdealGasLaw::VolumeInput.toFloat() <= 0.0f)
    {
        QMessageBox::about(this, "Error", "Invalid Input! Please Enter A Valid Number.");
    } else {
        VolumeValue = std::stod(IdealGasLaw::VolumeInput.toStdString());
        PressureValue = (IdealGasLaw::mole*R*TempAdjust)/VolumeValue;
        QMessageBox::about(this, "Pressure Value", "The pressure is " + QString::number(PressureValue) + " atm.");
    }
}

