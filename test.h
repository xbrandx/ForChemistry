#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QWidget>
#include <QString>
#include "label.h"

class test
{
public:
    QWidget * parent;
    test(QWidget *par);
    ~test();
    void Clear();
    QString Name();
};

#endif // TEST_H
