#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QString>
#include "formula.h"

class ComboBox : public QComboBox
{
public:
    ComboBox(int a, int b, int x, int y, QWidget * par);
};

#endif // COMBOBOX_H
