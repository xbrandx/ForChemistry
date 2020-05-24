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
    double PressureValue = 1;
    double VolumeValue;
    double R = 8.0821;

    VolumeValue = (IdealGasLaw::mole*R*IdealGasLaw::temperature)/PressureValue;

    QMessageBox::about(this, "Message", "Volume is " + QString::number(VolumeValue));
}

void PushButton::GasLaw_Pressure()
{
    double PressureValue;
    double VolumeValue = 1;
    double R = 8.0821;

    PressureValue = (IdealGasLaw::mole*R*IdealGasLaw::temperature)/VolumeValue;

    QMessageBox::about(this, "Message", "Pressure is " + QString::number(PressureValue));
}

