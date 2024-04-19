#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QElapsedTimer>

#include "juego.h"

class Graficos : public QWidget
{
    Q_OBJECT
public:
    explicit Graficos(QWidget *parent = 0);
    bool Turno(void);
    bool Fin = false;
    bool F = false;
    int NumerodeTurno = 1;

public slots:

private slots:

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event);


 signals:
    void TurnoJugador();


private:
    void paint (QPainter *painter, QPaintEvent *event);
    int x = -1, y = -1;
    int w = 1;
    int pieza;
    Juego game;
    QString piece;
    QPoint celdaSel;
    QPoint celdaCursor;
    bool FichaSeleccionada = false;
    bool TurnoBlancas = true;
    bool C = false;
    bool D = false;
    bool Enroque = false;
    void DibujarPiezas (QPainter *painter, QPaintEvent *event);
    void DibujarTablero(QPainter *painter, QPaintEvent *event);
    void Sugerencias (QPainter *painter, QPaintEvent *event);
    void MoverFicha(int m, int n);
    void IntentarMovida(int m, int n);
    bool EsViaLibre(int m, int n);
    void RealizarMovida (int m, int n);
    bool MoverPeon (int m, int n);
    bool MoverAlfil (int m, int n);
    bool MoverCaballo (int m, int n);
    bool MoverTorre (int m, int n);
    bool MoverReina (int m, int n);
    bool MoverRey (int m, int n);
    void CancelarMovida (void);
    void JaqueMate (void);
  };

#endif // GRAFICOS_H
