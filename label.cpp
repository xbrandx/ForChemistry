#include "label.h"

Label::Label(QWidget *par)
    :QLabel(par)
{
    setText("Mole #: ");
    move(100,30);
    show();
}
