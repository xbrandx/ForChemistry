#ifndef DOUBLESPINBOX_H
#define DOUBLESPINBOX_H

#include <QObject>
#include <QWidget>
#include <QDoubleSpinBox>
#include <QString>

class DoubleSpinBox : public QDoubleSpinBox
{
public:
    DoubleSpinBox(int a, double b, double c, double d, double e, int x, int y, QString s, QWidget * par);
};

#endif // DOUBLESPINBOX_H
