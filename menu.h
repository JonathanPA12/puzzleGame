//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//

#ifndef PUZZLEGAME_MENU_H
#define PUZZLEGAME_MENU_H

#include <stdlib.h>
#include <stdio.h>

const char* menuNombre();
const char* menuInicio(const int filas, const int columnas, int matriz[filas][columnas], const int cant);
void menuImprimirMatriz(const int filas, const int columnas, int matriz[filas][columnas], const int cant); //funcion para imprimir la matriz
void menuTeclas();
void msjMovInvalido();
void msjGanado();
void msjPerdido();
const char menuMovimiento();

#endif //PUZZLEGAME_MENU_H
