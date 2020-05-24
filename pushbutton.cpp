#include "pushbutton.h"

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
    QMessageBox::about(this, "Message", "Volume is Volume.");
}

void PushButton::GasLaw_Pressure()
{
    QMessageBox::about(this, "Message", "Pressure is Pressure.");
}

