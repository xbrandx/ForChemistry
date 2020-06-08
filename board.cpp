#include "board.h"
#include "ui_board.h"

#include <QDebug>

IdealGasLaw * gaslaw;

IsoThermal * iso;

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
    if (gaslaw) delete gaslaw;
    qDebug() << "1.before clear test0";
    if (iso) delete iso;
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
    if (iso) delete iso;
    qDebug() << "2.before clear gaslaw";
    if (gaslaw) delete gaslaw;
    qDebug() << "2.clear";
    resize(430, 200);
    iso = new IsoThermal(ui->centralWidget);
    setWindowTitle(iso->Name());
}
