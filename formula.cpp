#include "formula.h"

Formula::Formula(QWidget *par)
    :parent(par)
{

}

Formula::~Formula()
{
    Clear();
}

void Formula::Clear()
{
    qDebug() << "here?";
    while (!combos.empty())
    {
        ComboBox *c = combos.takeLast();
        if (c) delete c;
    }
    while (!doubles.empty())
    {
        DoubleSpinBox *d = doubles.takeLast();
        if (d) delete d;
    }
    while (!labels.empty())
    {
        Label *a = labels.takeLast();
        if (a) delete a;
    }
    while (!lines.empty())
    {
        LineEdit *e = lines.takeLast();
        if (e) delete e;
    }
    while (!pushs.empty())
    {
        PushButton *p = pushs.takeLast();
        if (p) delete p;
    }
}

void Formula::AddComboBox(ComboBox *c)
{
    combos.append(c);
}

void Formula::AddDoubleSpinBox(DoubleSpinBox *d)
{
    doubles.append(d);
}

void Formula::AddLabel(Label *a)
{
//    labels.append(a);
}

void Formula::AddLineEdit(LineEdit *e)
{
    lines.append(e);
}

void Formula::AddPushButton(PushButton *p)
{
    pushs.append(p);
}
