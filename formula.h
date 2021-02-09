#ifndef FORMULA_H
#define FORMULA_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QDebug>
#include "combobox.h"
#include "doublespinbox.h"
#include "label.h"
#include "lineedit.h"
#include "pushbutton.h"

class ComboBox;
class DoubleSpinBox;
class Label;
class LineEdit;
class PushButton;

class Formula
{
    QWidget *parent;
    QList<ComboBox *> combos;
    QList<DoubleSpinBox *> doubles;
    QList<Label *> labels;
    QList<LineEdit *> lines;
    QList<PushButton *> pushs;
public:
    Formula(QWidget *par);
    ~Formula();
    void Clear();
    void AddComboBox(ComboBox *c);
    void AddDoubleSpinBox(DoubleSpinBox *d);
    void AddLabel(Label *a);
    void AddLineEdit(LineEdit *e);
    void AddPushButton(PushButton *p);
    virtual QString FormulaName()=0;
};

#endif // FORMULA_H
