#include "board.h"
#include "ui_board.h"
#include <QDebug>

IdealGasLaw * gaslaw=0;

IsoThermal * iso=0;

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
    if (gaslaw)
    {
        delete gaslaw;
        gaslaw = 0;
    }
    if (iso)
    {
        delete iso;
        iso = 0;
    }
    resize(430,200);
    gaslaw = new IdealGasLaw(ui->centralWidget);
    setWindowTitle(gaslaw->Name());
}

void Board::on_actionExit_triggered()
{
    QApplication::quit();
}

void Board::on_actionIsoThermal_triggered()
{
    if (iso)
    {
        delete iso;
        iso = 0;
    }
    if (gaslaw)
    {
        delete gaslaw;
        gaslaw = 0;
    }
    resize(430, 300);
    iso = new IsoThermal(ui->centralWidget);
    setWindowTitle(iso->Name());
}
