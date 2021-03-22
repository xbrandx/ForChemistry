#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QDebug>
#include "formula.h"
#include "idealgaslaw.h"
#include "adiabatic.h"
#include "adiabatic_irrev.h"
#include "isobaric.h"
#include "isochoric.h"
#include "isothermal.h"
#include "isothermal_irrev.h"

class Formula;

QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE

class Board : public QMainWindow
{
    Q_OBJECT
public:
    Board(QWidget *parent = nullptr);
    ~Board();
private slots:
    void on_actionIdeal_Gas_Law_triggered();
    void on_actionAdiabatic_Reversible_triggered();
    void on_actionAdiabatic_Irreversible_triggered();
    void on_actionIsobaric_Process_triggered();
    void on_actionIsochoric_Process_triggered();
    void on_actionIsothermal_Process_triggered();
    void on_actionIsothermal_Process_Irreversible_triggered();
    void on_actionExit_triggered();
private:
    Ui::Board *ui;
};
#endif // BOARD_H
