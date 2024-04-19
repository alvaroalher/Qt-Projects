#include "mainwindow.h"
#include "ui_mainwindow.h"

int const MainWindow::EXIT_CODE_REBOOT = -123456789;

QAction* actionReboot;
QTimer* timer;
QTimer* timer2;
int min = 9;
int seg = 60;
int min2 = 9;
int seg2 = 60;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QGridLayout *grid = new QGridLayout();
    ui->setupUi(this);
    ui->frame->setLayout(grid);
    grid->addWidget(&graf);
    this->setFixedSize(810,610);
    Juego nuevojuego;
    nuevojuego.inicio();
    nuevojuego.imprime();
    this->setWindowTitle("Ajedrez");
    this->setWindowIcon(QIcon(":/iconos/chess"));

    actionReboot = new QAction(this);
    actionReboot->setText( tr("Restart"));
    actionReboot->setStatusTip( tr("Restart the app"));
    connect( actionReboot, SIGNAL(triggered()), this, SLOT (slotReboot()));


    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer->stop();

    timer2 = new QTimer(this);
    timer2->setInterval(1000);
    connect(timer2,SIGNAL(timeout()), this, SLOT(timer2_timeout()));
    timer2->stop();

    connect(&graf, SIGNAL(TurnoJugador()), this, SLOT(tempos()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotReboot(){
    qDebug() <<"Reinicia aplicacion";
    qApp->exit(MainWindow::EXIT_CODE_REBOOT);
}


void MainWindow::on_actionNuevo_Juego_triggered()
{
    actionReboot->trigger();
}

void MainWindow::on_actionJuego_con_Timer_triggered()
{
    F = true;
    graf.F = true;
    if((graf.NumerodeTurno % 2) != 0){
    timer->start();
    } else {
        timer2->start();
    }
}

void MainWindow::timer_timeout(){
    seg--;
    ui->lbl_segB->setText(QString::number(seg));
    ui->lbl_minB->setText(QString::number(min));
    if(seg == 0){
        min = min-1;
        seg = 59;
    }
    if(F == true){
    if(min < 0 || graf.Fin == true){
            timer->stop();
            QMessageBox::critical(this, "Ajedrez", "FIN DEL JUEGO, GANAN NEGRAS");
        }
    }
}


void MainWindow::timer2_timeout(){
    seg2--;
    ui->lbl_segN->setText(QString::number(seg2));
    ui->lbl_minN->setText(QString::number(min2));
    if(seg2 == 0){
        min2 -= 1;
        seg2 = 59;
    }
    if(F == true){
     if (min2 < 0 || graf.Fin == true){
            timer2->stop();
            QMessageBox::critical(this, "Ajedrez", "FIN DEL JUEGO, GANAN BLANCAS");
        }
    }
}


void MainWindow::tempos(){
 if(graf.NumerodeTurno != 0){
    if(F == true){
    int tm = graf.NumerodeTurno;
   if((tm % 2) != 0){
       timer->start();
       timer2->stop();
   }
   else if (tm % 2 == 0){
         timer->stop();
         timer2->start();
     }
}
        qDebug() << graf.NumerodeTurno;
} else{
     timer->stop();
     timer2->stop();
 }

}
