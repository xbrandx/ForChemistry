#include "combobox.h"

ComboBox::ComboBox(int x, int y,
                   QWidget *par)
    : QComboBox(par)
{
    move(x,y);
    show();
}
