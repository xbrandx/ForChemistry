#include "lineedit.h"

LineEdit::LineEdit(int x, int y,
                   QWidget *par)
    : QLineEdit(par)
{
    move(x,y);
    show();
}
