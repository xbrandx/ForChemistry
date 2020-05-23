#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QObject>
#include <QWidget>
#include <QComboBox>

class ComboBox : public QComboBox
{
public:
    ComboBox(int x, int y, QWidget * par);
};

#endif // COMBOBOX_H
