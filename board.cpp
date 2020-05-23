#include "idealgaslaw.h"
#include "board.h"
#include "ui_board.h"

IdealGasLaw * gaslaw;

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
    resize(500,200);
    gaslaw = new IdealGasLaw(ui->centralWidget);
}

void Board::on_actionExit_triggered()
{
    QApplication::quit();
}
