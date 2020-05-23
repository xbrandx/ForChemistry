#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

class LineEdit : public QLineEdit
{
public:
    LineEdit(int x, int y, QWidget * par);
};

#endif // LINEEDIT_H
