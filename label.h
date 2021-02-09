#ifndef LABEL_H
#define LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>
#include "formula.h"

class Label : public QLabel
{
public:
    Label(QString t, int x, int y, QWidget * par);
};

#endif // LABEL_H
