#ifndef FORMULA_H
#define FORMULA_H

#include <QObject>
#include <QWidget>
#include "combobox.h"

class ComboBox;

class Formula
{
    QWidget *parent;
    QList<ComboBox *> combos;
public:
    Formula(QWidget *par);
    virtual ~Formula();
    void Clear();

    void AddComboBox(ComboBox *c);
};

#endif // FORMULA_H
