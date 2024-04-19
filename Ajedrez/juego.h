#ifndef JUEGO_H
#define JUEGO_H

#include <QWidget>
#include <QDebug>


class Juego : public QWidget
{
    Q_OBJECT
public:
    explicit Juego(QWidget *parent = 0);
    void inicio(void);
    void imprime(void);
    QString asignapiezas(int n);
    int piezaselect(int m, int n);
    bool EsCeldanula(int m, int n);
    bool EsPiezaBlanca(int m, int n);
    int A[8][8];

signals:

public slots:

private:


    };

#endif // JUEGO_H
