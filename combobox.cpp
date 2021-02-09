#include "combobox.h"

ComboBox::ComboBox(int a, int b, int x, int y,
                   QWidget *par)
    : QComboBox(par)
{
    move(x,y);
    setMaxCount(a);
    for (int i = 1; i <= b; i++)
        this->addItem(QString::number(i));
    show();
}
