#ifndef DOUBLESPINBOX_H
#define DOUBLESPINBOX_H

#include <QObject>
#include <QWidget>
#include <QDoubleSpinBox>

class DoubleSpinBox : public QDoubleSpinBox
{
public:
    DoubleSpinBox(int x, int y, QWidget * par);
};

#endif // DOUBLESPINBOX_H
