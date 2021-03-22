#include "board.h"
#include "ui_board.h"

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
    if (formula) formula->Clear();
    resize(430,200);
    formula = new IdealGasLaw(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionAdiabatic_Reversible_triggered()
{
    if (formula) formula->Clear();
    resize(450,380);
    formula = new Adiabatic(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionAdiabatic_Irreversible_triggered()
{
    if (formula) formula->Clear();
    resize(450,380);
    formula = new Adiabatic_Irrev(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionIsobaric_Process_triggered()
{
    if (formula) formula->Clear();
    resize(450,380);
    formula = new Isobaric(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionIsochoric_Process_triggered()
{
    if (formula) formula->Clear();
    resize(450,280);
    formula = new Isochoric(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionIsothermal_Process_triggered()
{
    if (formula) formula->Clear();
    resize(450,420);
    formula = new Isothermal(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionIsothermal_Process_Irreversible_triggered()
{
    if (formula) formula->Clear();
    resize(450,380);
    formula = new Isothermal_Irrev(ui->centralWidget);
    setWindowTitle(formula->FormulaName());
}

void Board::on_actionExit_triggered()
{
    QApplication::quit();
}
