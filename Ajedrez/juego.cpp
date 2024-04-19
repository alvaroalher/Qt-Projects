#include "juego.h"

Juego::Juego(QWidget *parent) : QWidget(parent)
{

}

void Juego::inicio(void){
    for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                A[i][j]=0;
            }
        }

        for(int i=0; i<8; ++i){
            A[1][i]--;
            A[6][i]++;
        }

        for(int i=0; i<2; ++i){
            A[0][0]--;
            A[0][7]--;
            A[7][0]++;
            A[7][7]++;
        }

        for (int i=0; i<3; ++i){
            A[0][1]--;
            A[0][6]--;
            A[7][1]++;
            A[7][6]++;
        }

        for (int i=0; i<4; ++i){
            A[0][2]--;
            A[0][5]--;
            A[7][2]++;
            A[7][5]++;
        }

        A[0][3] = -5;
        A[7][3] = 5;
        A[0][4] = -6;
        A[7][4] = 6;
}

void Juego::imprime(void){
    for(int i=0; i<8; ++i){
       qDebug() << A[i][0] << A[i][1] << A[i][2] << A[i][3] << A[i][4] << A[i][5] << A[i][6] << A[i][7];
    }
}

QString Juego::asignapiezas(int n){
    QString pieza;
    switch(n){
    case -6:
        pieza = ":/negro/rey";
        break;
    case -5:
        pieza = ":/negro/reina";
        break;
    case -4:
        pieza = ":/negro/alfil";
        break;
    case -3:
        pieza = ":/negro/caballo";
        break;
    case -2:
        pieza = ":/negro/torre";
        break;
    case -1:
        pieza = ":/negro/peon";
        break;
    case 1:
        pieza = ":/blanco/peon";
        break;
    case 2:
        pieza = ":/blanco/torre";
        break;
    case 3:
        pieza = ":/blanco/caballo";
        break;
    case 4:
        pieza = ":/blanco/alfil";
        break;
    case 5:
        pieza = ":/blanco/reina";
        break;
    case 6:
        pieza = ":/blanco/rey";
        break;

}
    return pieza;
}

int Juego::piezaselect(int m, int n){
    int z;
    z = A[n][m];
    return z;
}

bool Juego::EsCeldanula(int m, int n){
    bool f;
    if(A[n][m] == 0){
        f = true;
    } else{
        f = false;
    }
    return f;
}

bool Juego::EsPiezaBlanca(int m, int n){
    bool f;
    if(A[n][m]>0){
        f = true;
    } else{
        f = false;
 }
    return f;
}
