#include "doublespinbox.h"

DoubleSpinBox::DoubleSpinBox(int x, int y,
                             QWidget *par)
    : QDoubleSpinBox(par)
{
    move(x,y);
    show();
}
