#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QWidget>
#include "label.h"

class test
{
public:
    QWidget * parent;
    test(QWidget *par);
    ~test();
    void Clear();
};

#endif // TEST_H
