//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//

#ifndef PUZZLEGAME_JUEGO_H
#define PUZZLEGAME_JUEGO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define FILAS 4
#define COLUMNAS 4
#define CANT FILAS*COLUMNAS

struct posicion{ //utulizar typedef
    int i;
    int j;
    int val;
};
struct jugador{
    const char *name;
    int cantMovs;
    char gano[3];
};

extern struct posicion posActual;
extern struct posicion posMovimiento;
extern struct jugador player;
extern FILE *archivo;
extern int matriz[FILAS][COLUMNAS];

void llenarMatriz(); //funcion para llenar la matriz
void iniciar();
void posicionActual();
bool opcionesMovimientos(int);
void moverArriba();
void moverAbajo();
void moverDerecha();
void moverIzquierda();
void intercambiar();
bool jugada(int);
void posicionMovimiento();
bool ganar();
void guardarMarcador(FILE *archivo);

#endif //PUZZLEGAME_JUEGO_H
