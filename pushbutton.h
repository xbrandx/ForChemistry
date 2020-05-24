#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMouseEvent>
#include <QMessageBox>

class IdealGasLaw;

class PushButton : public QPushButton
{
public:
    QString program;
    PushButton(QString t, QString p, int x, int y, QWidget * par);
    void mousePressEvent(QMouseEvent * ev);
    void GasLaw_Volume();
    void GasLaw_Pressure();
};

#endif // PUSHBUTTON_H
