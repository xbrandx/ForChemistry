#include "lineedit.h"

extern Formula *formula;

LineEdit::LineEdit(int x, int y,
                   QWidget *par)
    : QLineEdit(par)
{
    move(x,y);
    formula->AddLineEdit(this);
    show();
}
