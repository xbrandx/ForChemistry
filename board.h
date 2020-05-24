#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "idealgaslaw.h"

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

    void on_actionExit_triggered();

private:
    Ui::Board *ui;
};
#endif // BOARD_H
