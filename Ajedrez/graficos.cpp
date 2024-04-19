#include "graficos.h"


Graficos::Graficos(QWidget *parent) : QWidget(parent)
{
    game.inicio();
}



void Graficos::paintEvent (QPaintEvent *event){
   //Objeto que pinta en el UI
    QPainter painter;
    painter.begin (this);
    paint(&painter, event);
    painter.end();
}


void Graficos::paint (QPainter *painter, QPaintEvent *event){
    //Dibujar un rectangulo para base tablero
   DibujarTablero(painter, event);
   //Dibujar piezas
   DibujarPiezas(painter, event);
   Sugerencias(painter,event);
 }

void Graficos::DibujarTablero(QPainter *painter, QPaintEvent *event){
    int i, j;
    painter->setBrush(QBrush(QColor(255,255,255)));
    painter->drawRect(0,0,480,480);

    for(j=0; j<480; j+=120){
        for(i=0; i<480; i+=120){
            painter->setBrush(QBrush(QColor(204,204,255)));
            painter->drawRect(j,i,60,60);

            painter->setBrush(QBrush(QColor(81,157,255)));
            painter->drawRect(j,i+60,60,60);
        }
    }
    for(i=60; i<480; i+=120){
        for(j=0; j<480; j+=120){
            painter->setBrush(QBrush(QColor(81,157,255)));
            painter->drawRect(i,j,60,60);
            painter->setBrush(QBrush(QColor(204,204,255)));
            painter->drawRect(i,j+60,60,60);

        }
    }
}

void Graficos::Sugerencias(QPainter *painter, QPaintEvent *event){
    int n = game.piezaselect(celdaSel.x(), celdaSel.y());
    painter->setBrush(QBrush(QColor(255,188,0,150)));
    int xi = celdaSel.x();
    int yi = celdaSel.y();
    int j;

    switch (n) {
    case 1: //PEONB
        if(celdaSel.y() == 6 && game.EsCeldanula(xi, yi-1) && game.EsCeldanula(xi, yi-2)){
        painter->drawRect(celdaSel.x()*60, (celdaSel.y()-1)*60,60,60);
        painter->drawRect(celdaSel.x()*60, (celdaSel.y()-2)*60,60,60);
        }
        else if(game.EsCeldanula(xi, yi-1)){
         painter->drawRect(celdaSel.x()*60, (celdaSel.y()-1)*60,60,60);
            }

        if(!game.EsPiezaBlanca(celdaSel.x()-1, celdaSel.y()-1) && !game.EsCeldanula(celdaSel.x()-1, celdaSel.y()-1)){
            if(xi != 0){
            painter->drawRect((celdaSel.x()-1)*60, (celdaSel.y()-1)*60, 60,60);
            }
        }
        if(!game.EsPiezaBlanca(celdaSel.x()+1, celdaSel.y()-1) && !game.EsCeldanula(celdaSel.x()+1, celdaSel.y()-1)){
            if(xi != 7){
            painter->drawRect((celdaSel.x()+1)*60, (celdaSel.y()-1)*60, 60,60);
            }
        }
        break;

    case -1: //PEONN
        if(celdaSel.y() == 1 && game.EsCeldanula(xi, yi+1) && game.EsCeldanula(xi, yi+2)){
        painter->drawRect(celdaSel.x()*60, (celdaSel.y()+1)*60,60,60);
        painter->drawRect(celdaSel.x()*60, (celdaSel.y()+2)*60,60,60);
        }
        else if (game.EsCeldanula(xi, yi+1)){
         painter->drawRect(celdaSel.x()*60, (celdaSel.y()+1)*60,60,60);
        }
        if(game.EsPiezaBlanca(celdaSel.x()-1, celdaSel.y()+1) && !game.EsCeldanula(celdaSel.x()-1, celdaSel.y()+1)){
            if(xi != 0){
            painter->drawRect((celdaSel.x()-1)*60, (celdaSel.y()+1)*60, 60,60);
            }
        }
        if(game.EsPiezaBlanca(celdaSel.x()+1, celdaSel.y()+1) && !game.EsCeldanula(celdaSel.x()+1, celdaSel.y()+1)){
            if(xi != 7){
            painter->drawRect((celdaSel.x()+1)*60, (celdaSel.y()+1)*60, 60,60);
            }
        }
        break;

    case 6: //REYB
            if(!game.EsPiezaBlanca(xi-1, yi-1) || game.EsCeldanula(xi-1,yi-1)){
                painter->drawRect((xi-1)*60, (yi-1)*60, 60,60);
            }
            if(!game.EsPiezaBlanca(xi, yi-1) || game.EsCeldanula(xi,yi-1)){
                painter->drawRect((xi)*60, (yi-1)*60, 60,60);
            }
            if(!game.EsPiezaBlanca(xi+1, yi-1) || game.EsCeldanula(xi+1,yi-1)){
                painter->drawRect((xi+1)*60, (yi-1)*60, 60,60);
            }
            if(!game.EsPiezaBlanca(xi-1, yi) || game.EsCeldanula(xi-1,yi)){
                painter->drawRect((xi-1)*60, (yi)*60, 60,60);
            }
            if(!game.EsPiezaBlanca(xi+1, yi) || game.EsCeldanula(xi+1,yi)){
                painter->drawRect((xi+1)*60, (yi)*60, 60,60);
            }
            if(yi != 7){
            if((!game.EsPiezaBlanca(xi-1, yi+1)) || (game.EsCeldanula(xi-1,yi+1))){
                painter->drawRect((xi-1)*60, (yi+1)*60, 60,60);
            }
            if((!game.EsPiezaBlanca(xi, yi+1)) || (game.EsCeldanula(xi,yi+1))){
                painter->drawRect((xi)*60, (yi+1)*60, 60,60);
            }
            if((!game.EsPiezaBlanca(xi+1, yi+1)) || (game.EsCeldanula(xi+1,yi+1))){
                painter->drawRect((xi+1)*60, (yi+1)*60, 60,60);
            }
            }

            if (EsViaLibre(xi-3, yi) && (C == false) && game.A[7][0] == 2){
                painter->drawRect((xi-1)*60, (yi)*60, 60, 60);
                painter->drawRect((xi-2)*60, yi*60, 60,60);
            }
            if (EsViaLibre(xi+3, yi) && (C == false) && game.A[7][7] == 2){
                painter->drawRect((xi+1)*60, yi*60, 60,60);
                painter->drawRect((xi+2)*60, yi*60, 60,60);
            }
       break;

     case -6: //REYN
        if(yi != 0){
           if(game.EsPiezaBlanca(xi-1, yi-1) || game.EsCeldanula(xi-1,yi-1)){
                painter->drawRect((xi-1)*60, (yi-1)*60, 60,60);
            }
            if(game.EsPiezaBlanca(xi, yi-1) || game.EsCeldanula(xi,yi-1)){
                painter->drawRect((xi)*60, (yi-1)*60, 60,60);
            }
            if(game.EsPiezaBlanca(xi+1, yi-1) || game.EsCeldanula(xi+1,yi-1)){
                painter->drawRect((xi+1)*60, (yi-1)*60, 60,60);
            }
        }
            if(game.EsPiezaBlanca(xi-1, yi) || game.EsCeldanula(xi-1,yi)){
                painter->drawRect((xi-1)*60, (yi)*60, 60,60);
            }
            if(game.EsPiezaBlanca(xi+1, yi) || game.EsCeldanula(xi+1,yi)){
                painter->drawRect((xi+1)*60, (yi)*60, 60,60);
            }
            if((game.EsPiezaBlanca(xi-1, yi+1)) || (game.EsCeldanula(xi-1,yi+1))){
                painter->drawRect((xi-1)*60, (yi+1)*60, 60,60);
            }
            if((game.EsPiezaBlanca(xi, yi+1)) || (game.EsCeldanula(xi,yi+1))){
                painter->drawRect((xi)*60, (yi+1)*60, 60,60);
            }
            if((game.EsPiezaBlanca(xi+1, yi+1)) || (game.EsCeldanula(xi+1,yi+1))){
                painter->drawRect((xi+1)*60, (yi+1)*60, 60,60);
            }
            if (EsViaLibre(xi-3, yi) && (D == false) && game.A[0][0] == -2){
                painter->drawRect((xi-1)*60, (yi)*60, 60, 60);
                painter->drawRect((xi-2)*60, yi*60, 60,60);
            }
            if (EsViaLibre(xi+3, yi) && (D == false) && game.A[0][7] == -2){
                painter->drawRect((xi+1)*60, yi*60, 60,60);
                painter->drawRect((xi+2)*60, yi*60, 60,60);
            }
       break;

    case 2: //TORREB
        j = 1;
        if(yi != 0){
        while(game.EsCeldanula(xi, yi-j)){ //VERTICAL ARRIBA
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi, yi-j)){
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
        }
        }

        j = 1;
        if(yi != 7){
        while(game.EsCeldanula(xi, yi+j) && (yi+j)<7){ //VERTICAL ABAJO
            painter->drawRect(xi*60, (yi+j)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi, yi+j)){
              painter->drawRect(xi*60, (yi+j)*60, 60, 60);
        }
        }

        j = 1;
        if(xi != 0){
        while(game.EsCeldanula(xi-j, yi)){ //HORIZONTAL IZQUIERDA
            painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi-j, yi)){
             painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
        }
        }
        j = 1;
        if((xi != 7)){
        while(game.EsCeldanula(xi+j, yi) && (xi+j)<7){ //HORIZONTAL DERECHA
            painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi+j, yi)){
             painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
        }
        }
        break;

    case -2:
        j = 1;
        if(yi != 0){
        while(game.EsCeldanula(xi, yi-j)){ //VERTICAL ARRIBA
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi, yi-j)){
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
        }
        }

        j = 1;
        if(yi != 7){
        while(game.EsCeldanula(xi, yi+j) && (yi+j)<7){ //VERTICAL ABAJO
            painter->drawRect(xi*60, (yi+j)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi, yi+j) || game.EsCeldanula(xi, yi+j)){
              painter->drawRect(xi*60, (yi+j)*60, 60, 60);
        }
        }

        j = 1;
        if(xi != 0){
        while(game.EsCeldanula(xi-j, yi)){ //HORIZONTAL IZQUIERDA
            painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi-j, yi)){
             painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
        }
        }

        j = 1;
        if((xi != 7)){
        while(game.EsCeldanula(xi+j, yi) && (xi+j)<7){ //HORIZONTAL DERECHA
            painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
            j++;
        }
        if((xi+j)==7){
            painter->drawRect((xi+j)*60, yi*60,60,60);
        } else if(game.EsPiezaBlanca(xi+j, yi)){
             painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
        }
        }
        break;


    case 4: //ALFILB
        if(yi != 0){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi-j)){ //Arriba-izquierda
                   painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi-j, yi-j)){
                    painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi-j) && ((xi+j)<7)){ //Arriba-derecha
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi+j, yi-j)){
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
               }
        }
        }
               if(yi != 7){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi+j)){ //Abajo-izquierda
                   painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi-j, yi+j)){
                    painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi+j) && ((xi+j)<7)){ //Abajo-derecha
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi+j, yi+j)){
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
               }
               }
               }
               break;

    case -4: //ALFILN
        if(yi != 0){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi-j)){ //Arriba-izquierda
                   painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(game.EsPiezaBlanca(xi-j, yi-j)){
                    painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi-j) && ((xi+j)<7)){ //Arriba-derecha
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(game.EsPiezaBlanca(xi+j, yi-j) || game.EsCeldanula(xi+j,yi-j)){
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
               }
        }
        }
               if(yi != 7){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi+j)){ //Abajo-izquierda
                   painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(game.EsPiezaBlanca(xi-j, yi+j)){
                    painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi+j) && ((xi+j)<7)){ //Abajo-derecha
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
                   j++;
               }

               if(game.EsPiezaBlanca(xi+j, yi+j) || game.EsCeldanula(xi+j, yi+j)){
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
               }
               }
               }
               break;


    case 5: //REINAB
        j = 1;
        if(yi != 0){
        while(game.EsCeldanula(xi, yi-j)){ //VERTICAL ARRIBA
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi, yi-j)){
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
        }
        }

        j = 1;
        if(yi != 7){
        while(game.EsCeldanula(xi, yi+j) && (yi+j)<7){ //VERTICAL ABAJO
            painter->drawRect(xi*60, (yi+j)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi, yi+j)){
              painter->drawRect(xi*60, (yi+j)*60, 60, 60);
        }
        }

        j = 1;
        if(xi != 0){
        while(game.EsCeldanula(xi-j, yi)){ //HORIZONTAL IZQUIERDA
            painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi-j, yi)){
             painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
        }
        }
        j = 1;
        if((xi != 7)){
        while(game.EsCeldanula(xi+j, yi) && (xi+j)<7){ //HORIZONTAL DERECHA
            painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(!game.EsPiezaBlanca(xi+j, yi)){
             painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
        }
        }
        if(yi != 0){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi-j)){ //Arriba-izquierda
                   painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi-j, yi-j)){
                    painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi-j) && ((xi+j)<7)){ //Arriba-derecha
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi+j, yi-j)){
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
               }
        }
        }
               if(yi != 7){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi+j)){ //Abajo-izquierda
                   painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi-j, yi+j)){
                    painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi+j) && ((xi+j)<7)){ //Abajo-derecha
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(!game.EsPiezaBlanca(xi+j, yi+j)){
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
               }
               }
               }
               break;


    case -5:
        j = 1;
        if(yi != 0){
        while(game.EsCeldanula(xi, yi-j)){ //VERTICAL ARRIBA
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi, yi-j)){
            painter->drawRect(xi*60, (yi-j)*60, 60, 60);
        }
        }

        j = 1;
        if(yi != 7){
        while(game.EsCeldanula(xi, yi+j) && (yi+j)<7){ //VERTICAL ABAJO
            painter->drawRect(xi*60, (yi+j)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi, yi+j) || game.EsCeldanula(xi, yi+j)){
              painter->drawRect(xi*60, (yi+j)*60, 60, 60);
        }
        }

        j = 1;
        if(xi != 0){
        while(game.EsCeldanula(xi-j, yi)){ //HORIZONTAL IZQUIERDA
            painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
            j++;
        }
        if(game.EsPiezaBlanca(xi-j, yi)){
             painter->drawRect((xi-j)*60, (yi)*60, 60, 60);
        }
        }

        j = 1;
        if((xi != 7)){
        while(game.EsCeldanula(xi+j, yi) && (xi+j)<7){ //HORIZONTAL DERECHA
            painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
            j++;
        }
        if((xi+j)==7){
            painter->drawRect((xi+j)*60, yi*60,60,60);
        } else if(game.EsPiezaBlanca(xi+j, yi)){
             painter->drawRect((xi+j)*60, (yi)*60, 60, 60);
        }
        }
        if(yi != 0){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi-j)){ //Arriba-izquierda
                   painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if(game.EsPiezaBlanca(xi-j, yi-j)){
                    painter->drawRect((xi-j)*60, (yi-j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi-j) && ((xi+j)<7)){ //Arriba-derecha
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
                   j++;
               }
               if((xi+j) == 7){
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60,60);
               }
               if(game.EsPiezaBlanca(xi+j, yi-j)){
                   painter->drawRect((xi+j)*60, (yi-j)*60, 60, 60);
               }
        }
        }
               if(yi != 7){
               j = 1;
               if(xi != 0){
               while(game.EsCeldanula(xi-j, yi+j)){ //Abajo-izquierda
                   painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
                   j++;
               }
               if(game.EsPiezaBlanca(xi-j, yi+j)){
                    painter->drawRect((xi-j)*60, (yi+j)*60, 60, 60);
               }
               }
               j = 1;
               if(xi != 7){
               while(game.EsCeldanula(xi+j, yi+j) && ((xi+j)<7)){ //Abajo-derecha
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
                   j++;
               }

               if(game.EsPiezaBlanca(xi+j, yi+j) && ((xi+j) != 7)){
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
               }
               else if((xi+j) == 7){
                   painter->drawRect((xi+j)*60, (yi+j)*60, 60, 60);
               }
               }
               }
               break;


    case 3:
        if((game.EsCeldanula(xi+1, yi-2) || !game.EsPiezaBlanca(xi+1, yi-2))){ //ARRIBA, DERECHA
            if(xi < 7){
               painter->drawRect((xi+1)*60, (yi-2)*60,60,60);
            }
        }
        if(game.EsCeldanula(xi-1, yi-2) || !game.EsPiezaBlanca(xi-1, yi-2)){ //ARRIBA, IZQUIERDA
            painter->drawRect((xi-1)*60, (yi-2)*60,60,60);
        }
        if((game.EsCeldanula(xi+1, yi+2) || !game.EsPiezaBlanca(xi+1, yi+2))){ //ABAJO, DERECHA
            if(xi < 7){
            painter->drawRect((xi+1)*60, (yi+2)*60,60,60);
            }
        }
        if((game.EsCeldanula(xi-1, yi+2) || !game.EsPiezaBlanca(xi-1, yi+2)) && (yi != 7)){ // ABAJO, IZQUIERDA
            if(yi < 6){
            painter->drawRect((xi-1)*60, (yi+2)*60,60,60);
            }
        }

        if(game.EsCeldanula(xi+2, yi-1) || !game.EsPiezaBlanca(xi+2, yi-1)){//DERECHA, ARRIBA
            if(xi < 6){
            painter->drawRect((xi+2)*60, (yi-1)*60,60,60);
            }
        }
        if((game.EsCeldanula(xi+2, yi+1) || !game.EsPiezaBlanca(xi+2, yi+1)) && ((yi != 7) && (xi != 7))){ //DERECHA, ABAJO
            if(xi < 6){
            painter->drawRect((xi+2)*60, (yi+1)*60,60,60);
        }
        }
        if(game.EsCeldanula(xi-2, yi-1) || !game.EsPiezaBlanca(xi-2, yi-1)){ //IZQUIERDA, ARRIBA
            painter->drawRect((xi-2)*60, (yi-1)*60,60,60);
        }
        if((game.EsCeldanula(xi-2, yi+1) || !game.EsPiezaBlanca(xi-2, yi+1)) && (yi != 7)){ //IZQUIERDA, ABAJO
            if(yi < 7){
            painter->drawRect((xi-2)*60, (yi+1)*60,60,60);
            }
        }
        break;

    case -3:
        if(game.EsCeldanula(xi+1, yi-2) || game.EsPiezaBlanca(xi+1, yi-2)){ //ARRIBA, DERECHA
            if(xi < 7){
            painter->drawRect((xi+1)*60, (yi-2)*60,60,60);
            }
        }
        if(game.EsCeldanula(xi-1, yi-2) || game.EsPiezaBlanca(xi-1, yi-2)){ //ARRIBA, IZQUIERDA
            painter->drawRect((xi-1)*60, (yi-2)*60,60,60);
        }
        if(game.EsCeldanula(xi+1, yi+2) || game.EsPiezaBlanca(xi+1, yi+2)){ //ABAJO, DERECHA
            if(xi < 7){
            painter->drawRect((xi+1)*60, (yi+2)*60,60,60);
            }
        }
        if(game.EsCeldanula(xi-1, yi+2) || game.EsPiezaBlanca(xi-1, yi+2)){ // ABAJO, IZQUIERDA
            painter->drawRect((xi-1)*60, (yi+2)*60,60,60);
        }

        if(game.EsCeldanula(xi+2, yi-1) || game.EsPiezaBlanca(xi+2, yi-1)){ //DERECHA, ARRIBA
            if(xi < 6){
            painter->drawRect((xi+2)*60, (yi-1)*60,60,60);
            }
        }
        if(game.EsCeldanula(xi+2, yi+1) || game.EsPiezaBlanca(xi+2, yi+1)){ //DERECHA, ABAJO
            if (xi < 6){
            painter->drawRect((xi+2)*60, (yi+1)*60,60,60);
            }
        }
        if(game.EsCeldanula(xi-2, yi-1) || game.EsPiezaBlanca(xi-2, yi-1)){ //IZQUIERDA, ARRIBA
            painter->drawRect((xi-2)*60, (yi-1)*60,60,60);
        }
        if(game.EsCeldanula(xi-2, yi+1) || game.EsPiezaBlanca(xi-2, yi+1)){ //IZQUIERDA, ABAJO
            painter->drawRect((xi-2)*60, (yi+1)*60,60,60);
        }
        break;

    }
}


void Graficos::DibujarPiezas(QPainter *painter, QPaintEvent *event){
    int n;
    for(x=0; x<8; x++){
          for(y=0; y<8; y++){
              n = game.piezaselect(x,y);
              piece = game.asignapiezas(n);
              if(n != 0){
              QImage pieza (piece);
              painter->drawImage(x*60, y*60, pieza);
              }
           }
        }
 }



void Graficos::mousePressEvent(QMouseEvent *event){
    int m, n;
    m = event->pos().x();
    n = event->pos().y();

    x = m/60;
    y = n/60;


    if(x>-1 && y>-1 && x<8 && y<8){
        MoverFicha(x,y);
        emit TurnoJugador();
        game.imprime();
        JaqueMate();
        QWidget::update();
    }
}


void Graficos::MoverFicha(int m, int n){
    if(FichaSeleccionada){
        if(game.EsCeldanula(m,n) || (!game.EsPiezaBlanca(m,n) && TurnoBlancas) || (game.EsPiezaBlanca(m,n) && !TurnoBlancas)){
            IntentarMovida(m,n);
        }
        else {
            QMessageBox::critical(this, "Ajedrez", "Movida no permitida");
            CancelarMovida();
            }

    }
    else {
        if(game.EsCeldanula(m,n))
            return;
        if((game.EsPiezaBlanca(m,n) && TurnoBlancas) || (!game.EsPiezaBlanca(m,n) && !TurnoBlancas)){
            celdaSel.setX(m);
            celdaSel.setY(n);
            FichaSeleccionada = true;
             }
    }
}

void Graficos::IntentarMovida(int m, int n){
    int PiezaActual = game.A[celdaSel.y()][celdaSel.x()];
    bool SePuedeMover = false;

    switch (PiezaActual) {
    case 1:
    case -1:
        SePuedeMover = MoverPeon(m,n);
        break;

    case 4:
    case -4:
        SePuedeMover = MoverAlfil(m,n);
        break;

    case 3:
    case -3:
        SePuedeMover = MoverCaballo(m,n);
        break;

    case 6:
    case -6:
        SePuedeMover = MoverRey(m,n);
        break;

    case 5:
    case -5:
        SePuedeMover = MoverReina(m,n);
        break;

    case 2:
    case -2:
        SePuedeMover = MoverTorre(m,n);
        break;

    }

    if(SePuedeMover){
        RealizarMovida(m,n);
    }
    else{
        QMessageBox::critical(this, "Ajedrez", "Movida incorrecta");
        CancelarMovida();
        }

}

bool Graficos::EsViaLibre (int m, int n){

    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    bool ok = true;

    if (difx == 0){ //Movimiento vertical
        for(int i = 1; i< abs(dify); i++){
            if(game.A[celdaSel.y() + (dify<0?-i:i)][celdaSel.x()] != 0){
                ok = false;
            }
          }
}
else if (dify == 0){    //Movimiento horizontal
        for(int i = 1; i < abs(difx); i++){
            if(game.A[celdaSel.y()][celdaSel.x() + (difx<0?-i:i)] != 0){
                ok = false;
            }
        }
    }
else if (abs(difx) == abs(dify)){   //Movimiento diagonal
        for(int i = 1; i< abs(dify); i++){
            if(game.A[celdaSel.y() + (dify<0?-i:i)][celdaSel.x() + (difx<0?-i:i)] != 0){
                ok = false;
            }
        }
    }
      return ok;
}

void Graficos::RealizarMovida(int m, int n){
    //Cambiar turno
    TurnoBlancas = !TurnoBlancas;


    if(game.A[celdaSel.y()][celdaSel.x()] == 2){
        C = true;
    } else if(game.A[celdaSel.y()][celdaSel.x()] == -2){
        D = true;
    }

    //Asignar pieza de origen al destino
    game.A[n][m] = game.A[celdaSel.y()][celdaSel.x()];


    //Coronacion
    if((game.A[celdaSel.y()][celdaSel.x()] == 1) && n == 0){
        game.A[n][m] = game.A[celdaSel.y()][celdaSel.x()] + 4;
    } else if((game.A[celdaSel.y()][celdaSel.x()] == -1) && n == 7){
        game.A[n][m] = game.A[celdaSel.y()][celdaSel.x()] - 4;
    }

    //Enroque
    if(Enroque == true){
        if(game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && m == celdaSel.x()+2 && EsViaLibre(m,n)){ //Enroque corto blancas
            game.A[7][7] = 0;
            game.A[n][m] = game.A[celdaSel.y()][celdaSel.x()];
            game.A[n][m-1] = 2;
            C = true;
            Enroque = false;
        } else if (game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && m == celdaSel.x()-2 && EsViaLibre(m,n)){
            game.A[7][0] = 0;
            game.A[7][3] = 2;
            C = true;
            Enroque = false;
        }
         else if(!game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && m == celdaSel.x()+2 && EsViaLibre(m,n)){ //Enroque corto negras
            game.A[0][7] = 0;
            game.A[n][m] = game.A[celdaSel.y()][celdaSel.x()];
            game.A[n][m-1] = -2;
            D = true;
            Enroque = false;
        } else if (!game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && m == celdaSel.x()-2 && EsViaLibre(m,n)){
            game.A[0][0] = 0;
            game.A[0][3] = -2;
            D = true;
            Enroque = false;
        }
    }


    game.A[celdaSel.y()][celdaSel.x()] = 0;
    FichaSeleccionada = false;
    NumerodeTurno ++;
    celdaSel.setX(-1);
    celdaSel.setY(-1);
    }

bool Graficos::MoverPeon(int m, int n){
    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    bool MovidaPosible = false;

    if(difx == 0){
        if(abs(dify) == 1){ //Movida normal peon
          if(dify == game.EsPiezaBlanca(celdaSel.x(), celdaSel.y())?-1:1){
              if(game.EsCeldanula(m,n)){
                    MovidaPosible = true;
              }

          }
        }
        else if (abs(dify) == 2){   //Movida larga peon
            if(celdaSel.y() == (game.EsPiezaBlanca(celdaSel.x(), celdaSel.y())?6:1)){
                if(game.EsCeldanula(m,n)){
                      MovidaPosible = true;
                }
            }
        }
    }
    //Intenta comer :v
    else if ((abs(difx) == 1) && (dify == (game.EsPiezaBlanca(celdaSel.x(), celdaSel.y())?-1:1)) && !game.EsCeldanula(m,n) && game.A[celdaSel.y()][celdaSel.x()] != game.A[n][m]){
        MovidaPosible = true;
    }
    return MovidaPosible;
    }

bool Graficos::MoverAlfil(int m, int n){

    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    if (abs(difx) == abs(dify)){
        if (EsViaLibre(m,n) && game.A[celdaSel.y()][celdaSel.x()] != game.A[n][m]){
            return true;
        }
    }

    return false;
}

bool Graficos::MoverTorre(int m, int n){

    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    if (difx == 0 || dify == 0 ){
        if (EsViaLibre(m,n) && game.A[celdaSel.y()][celdaSel.x()] != game.A[n][m]){
            return true;
        }
    }
    return false;
}

bool Graficos::MoverReina(int m, int n){
    return MoverAlfil(m,n) || MoverTorre(m,n);
}

bool Graficos::MoverRey(int m, int n){

    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    if (((abs(difx) == 1) && (abs(dify) == 1)) || ((abs(difx) == 1) && (abs(dify) == 0)) || ((abs(difx) == 0) && (abs(dify) == 1))){
        if (game.A[celdaSel.y()][celdaSel.x()] != game.A[n][m]){
            return true;
        }
    } else if (game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && (difx == 2) && (C == false) && game.A[7][7] == 2){
        Enroque = true;
        C = true;
        return true;
    } else if(game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && (difx == -2) && (C == false) && game.A[7][0] == 2){
        Enroque = true;
        C = true;
        return true;
    } else if (!game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && (difx == 2) && (D == false) && game.A[0][7] == -2){
        Enroque = true;
        D = true;
        return true;
    } else if(!game.EsPiezaBlanca(celdaSel.x(), celdaSel.y()) && (difx == -2) && (D == false) && game.A[0][0] == -2){
        Enroque = true;
        D = true;
        return true;
    }
    return false;
}


bool Graficos::MoverCaballo(int m, int n){

    int dify = n - celdaSel.y();
    int difx = m - celdaSel.x();

    if (((abs(difx) == 2) && (abs(dify) == 1)) || ((abs(difx) == 1) && ((abs(dify)) == 2))){
        if (game.A[celdaSel.y()][celdaSel.x()] != game.A[n][m]){
            return true;
        }
    }
    return false;
}

void Graficos::CancelarMovida(void){
    if(FichaSeleccionada)
        FichaSeleccionada = false;
}


void Graficos::JaqueMate(void){
    int i, j, k = 0, l = 0;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            if(game.A[i][j] != 6){
                k++;
            } if(game.A[i][j] != -6){
                l++;
            }
        }
    }
    if(F == false){
   if(k == 64){
        QMessageBox::critical(this, "Jaque Mate", "FIN DEL JUEGO, GANAN NEGRAS");
    } else if(l == 64){
        QMessageBox::critical(this,"Jaque Mate", "FIN DEL JUEGO, GANAN BLANCAS");
    }
 }

    if(k == 64 || l == 64){
        Fin = true;
        NumerodeTurno = 0;
    }
}



bool Graficos::Turno(){
    return TurnoBlancas;
}
