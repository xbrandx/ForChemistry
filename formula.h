#ifndef FORMULA_H
#define FORMULA_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QDebug>

class Formula
{
    QWidget *parent;
public:
    Formula(QWidget *par);
    virtual ~Formula();
    virtual void Clear();
    virtual QString FormulaName()=0;
};

#endif // FORMULA_H
