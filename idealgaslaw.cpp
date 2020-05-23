#include "idealgaslaw.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"

IdealGasLaw::IdealGasLaw(QWidget *par)
    : parent(par)
{
    Label * label1 = new Label("Mole #: ", 30, 30, parent);
    Label * label2 = new Label("Temperature (C): ", 250, 30, parent);
    Label * label3 = new Label("Enter Pressure (atm): ", 30, 80, parent);
    Label * label4 = new Label("Enter Volume (L): ", 30, 120, parent);

    LineEdit * line1 = new LineEdit(180, 80, parent);
    LineEdit * line2 = new LineEdit(180, 120, parent);

    PushButton * button1 = new PushButton("Find Volume  ", 350, 80, parent);
    PushButton * button2 = new PushButton("Find Pressure", 350, 120, parent);
    button2->Click();

    ComboBox * combo = new ComboBox(10, 10, 80, 30, parent);

    DoubleSpinBox * spin = new DoubleSpinBox(2, -273, 1000, 0.5, 24, 350, 30, " C", parent);
}
