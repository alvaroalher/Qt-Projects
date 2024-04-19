#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

#include "graficos.h"
#include "juego.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int const EXIT_CODE_REBOOT;
    int CAMBIO_TIMER = 0;
    bool F = false;

private slots:
    void slotReboot();
    void on_actionNuevo_Juego_triggered();
    void timer_timeout();
    void timer2_timeout();
    void tempos();
    void on_actionJuego_con_Timer_triggered();

private:
    Ui::MainWindow *ui;
    Graficos graf;
    Juego game_i;


};

#endif // MAINWINDOW_H
