//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//
#include "juego.h"

struct posicion posActual = {0, 0, 0};
struct posicion posMovimiento = {0, 0, 0};
struct jugador player = {"", 0, "No"};
FILE *archivo;
int matriz[FILAS][COLUMNAS];

void llenarMatriz(){
    int vect[CANT]; //se usa un vector para almacenar numeros random sin repetirse del 1 al 15
    int cont = 0, new_random, upper = CANT-1; //el limite superior para generar randoms es el 15. CANT=4*4=16
    bool unique; //para verificar si el numero no esté repetido

    for (int i = 0; i<upper; i++)
    {
        do {
            new_random = (rand() % (upper - 1 + 1)) + 1;
            unique = true;
            for (int j = 0; j < i; j++) {
                if(vect[j]==new_random) unique=false;
            }
        }while(!unique); //mientras el numero se repita se realiza el bucle de generar random
        vect[i]= new_random; //agrego el numero al vector
    }

    vect[upper]= CANT;

    for (int i = 0; i<FILAS; i++)
    {
        for (int j = 0; j<COLUMNAS; j++)
        {
            matriz[i][j] = vect[cont]; // se llena la matriz con el vector de random
            cont++;
        }
        printf("\n");
    }
}

void iniciar(){
    llenarMatriz();
    posicionActual();
}

void posicionActual(){
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            if(matriz[i][j] == CANT){
                posActual.i = i;
                posActual.j = j;
                posActual.val = CANT;
            }
        }
    }
}

bool opcionesMovimientos(int flechaMov){
    if(posActual.i == 0 && posActual.j == 0){ //esquina sup izq
        switch (flechaMov) {
            case 100: //d
                moverDerecha();
                return true;
            case 115://s
                moverAbajo();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.i == FILAS-1 && posActual.j == 0){ //esquina inf izq
        switch (flechaMov) {
            case 100:
                moverDerecha();
                return true;
            case 119:
                moverArriba();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.i == 0 && posActual.j == COLUMNAS-1){ //esquina sup der
        switch (flechaMov) {
            case 97:
                moverIzquierda();
                return true;
            case 115:
                moverAbajo();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.i == FILAS-1 && posActual.j == COLUMNAS-1){ //esquina inf der
        switch (flechaMov) {
            case 97:
                moverIzquierda();
                return true;
            case 119:
                moverArriba();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.i == 0){ // medios fila 1
        switch (flechaMov) {
            case 100:
                moverDerecha();
                return true;
            case 97:
                moverIzquierda();
                return true;
            case 115:
                moverAbajo();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.j == 0){ // medios columna 1
        switch (flechaMov) {
            case 100:
                moverDerecha();
                return true;
            case 119:
                moverArriba();
                return true;
            case 115:
                moverAbajo();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.i == FILAS-1){ // medios fila n
        switch (flechaMov) {
            case 100:
                moverDerecha();
                return true;
            case 119:
                moverArriba();
                return true;
            case 97:
                moverIzquierda();
                return true;
            default:
                return false;
        }
    }
    else if(posActual.j == COLUMNAS-1){ // medios columna n
        switch (flechaMov) {
            case 115:
                moverAbajo();
                return true;
            case 119:
                moverArriba();
                return true;
            case 97:
                moverIzquierda();
                return true;
            default:
                return false;
        }
    }
    else{ // centrales
        switch (flechaMov) {
            case 115:
                moverAbajo();
                return true;
            case 119:
                moverArriba();
                return true;
            case 97:
                moverIzquierda();
                return true;
            case 100:
                moverDerecha();
                return true;
            default:
                return false;
        }
    }
}

void moverArriba(){
    posMovimiento.i = posActual.i - 1; //disminuye fila
    posMovimiento.j = posActual.j; //misma columna
}

void moverAbajo(){
    posMovimiento.i = posActual.i + 1;
    posMovimiento.j = posActual.j;
}

void moverDerecha(){
    posMovimiento.i = posActual.i;
    posMovimiento.j = posActual.j + 1;
}

void moverIzquierda(){
    posMovimiento.i = posActual.i;
    posMovimiento.j = posActual.j - 1;
}

void intercambiar(){
    matriz[posActual.i][posActual.j] = posMovimiento.val;
    matriz[posMovimiento.i][posMovimiento.j] = posActual.val;
}

bool jugada(int mov){
    posicionActual();
    if(opcionesMovimientos(mov)){
        posicionMovimiento();
        intercambiar();
        return true;
    }
    else{
        return false;
    }
}

void posicionMovimiento(){
    posMovimiento.val = matriz[posMovimiento.i][posMovimiento.j];
}

bool ganar(){
    int contador = 1;
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            if(matriz[i][j] == contador){
                contador++;
            }
        }
    }
    return contador == 15 ? true : false;
}

void guardarMarcador(FILE *archivo){
    fprintf(archivo, "Jugador: %s\nMovimientos: %d\nGano: %s\n", player.name, player.cantMovs, player.gano);
}
