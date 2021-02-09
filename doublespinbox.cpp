#include "doublespinbox.h"

DoubleSpinBox::DoubleSpinBox(int a, double b, double c, double d, double e,
                             int x, int y,
                             QString s,
                             QWidget *par)
    : QDoubleSpinBox(par)
{
    move(x,y);
    setDecimals(a);
    setRange(b,c);
    setSingleStep(d);
    setValue(e);
    setSuffix(s);
    show();
}
