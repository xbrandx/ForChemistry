#ifndef ISOCHORIC_H
#define ISOCHORIC_H

#include <QObject>
#include <QWidget>
#include <QString>
#include "formula.h"

class Isochoric : public Formula
{
public:
    Isochoric(QWidget *par);
    ~Isochoric();
    void Clear();
    QString FormulaName();
};

#endif // ISOCHORIC_H
