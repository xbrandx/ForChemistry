#include "board.h"
#include "ui_board.h"
#include <QDebug>

Formula *formula;

Board::Board(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
    formula = NULL;
}

Board::~Board()
{
    delete ui;
}

void Board::on_actionIdeal_Gas_Law_triggered()
{
    qDebug() << "first?";
    if (formula) formula->Clear();
    qDebug() << "second?";
    resize(430,200);
    qDebug() << "third?";
    formula = new IdealGasLaw(ui->centralWidget);
    qDebug() << "fourth?";
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionIsoThermal_triggered()
{
    if (formula) formula->Clear();
    resize(430, 300);
    formula = new IsoThermal(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionExit_triggered()
{
    QApplication::quit();
}
