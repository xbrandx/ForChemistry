#include "isothermal.h"

Label * label11;

IsoThermal::IsoThermal(QWidget *par)
    : parent(par)
{
    label11 = new Label("Testing: ", 50, 50, parent);
}

IsoThermal::~IsoThermal()
{
    Clear();
}

void IsoThermal::Clear()
{
    delete label11;
    label11 = nullptr;
    return;
}

QString IsoThermal::Name()
{
    return "IsoThermal";
}
