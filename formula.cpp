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
    while (!combos.empty())
    {
        ComboBox *c = combos.takeLast();
        if (c) delete c;
    }
}

void Formula::AddComboBox(ComboBox *c)
{
    combos.append(c);
}
