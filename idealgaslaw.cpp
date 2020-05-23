#include "idealgaslaw.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "combobox.h"
#include "doublespinbox.h"

IdealGasLaw::IdealGasLaw(QWidget *par)
    :parent(par)
{
    Label * label1 = new Label("Mole #: ", 30, 30, parent);
    Label * label2 = new Label("Temperature (C): ", 250, 30, parent);
    Label * label3 = new Label("Enter Pressure (atm): ", 30, 80, parent);
    Label * label4 = new Label("Enter Volume (L): ", 30, 120, parent);

    LineEdit * line1 = new LineEdit(180, 80, parent);
    LineEdit * line2 = new LineEdit(180, 120, parent);

    PushButton * button1 = new PushButton("Find Volume  ", 380, 80, parent);
    PushButton * button2 = new PushButton("Find Pressure", 380, 120, parent);

    ComboBox * combo = new ComboBox(80, 30, parent);

    DoubleSpinBox * spin = new DoubleSpinBox(380, 30, parent);
}
