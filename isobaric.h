#ifndef ISOBARIC_H
#define ISOBARIC_H

#include <QObject>
#include <QWidget>
#include <QString>
#include "formula.h"

class Isobaric : public Formula
{
public:
    Isobaric(QWidget *par);
    ~Isobaric();
    void Clear();
    QString FormulaName();
};

#endif // ISOBARIC_H
