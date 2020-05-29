#include "test.h"

Label * label11;

test::test(QWidget *par)
    : parent(par)
{
    label11 = new Label("Testing: ", 50, 50, parent);
}

test::~test()
{
    Clear();
}

void test::Clear()
{
    delete label11;
}
