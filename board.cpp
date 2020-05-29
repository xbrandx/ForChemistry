#include "board.h"
#include "ui_board.h"

#include <QDebug>

IdealGasLaw * gaslaw;

test * test0;

Board::Board(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}


void Board::on_actionIdeal_Gas_Law_triggered()
{
    qDebug() << "1.before clear gaslaw";
    if (gaslaw) gaslaw->Clear();
    qDebug() << "1.before clear test0";
    if (test0) test0->Clear();
    qDebug() << "1.clear";
    resize(430,200);
    gaslaw = new IdealGasLaw(ui->centralWidget);
    setWindowTitle(gaslaw->Name());
}

void Board::on_actionExit_triggered()
{
    QApplication::quit();
}

void Board::on_actiontest_triggered()
{
    qDebug() << "2.before clear test0";
    if (test0) test0->Clear();
    qDebug() << "2.before clear gaslaw";
    if (gaslaw) gaslaw->Clear();
    qDebug() << "2.clear";
    resize(200, 200);
    test0 = new test(ui->centralWidget);
}
