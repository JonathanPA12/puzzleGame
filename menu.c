//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//

#include "menu.h"

const char* menuNombre(){
    char *nombre, c;
    int i = 0;
    nombre = (char*)malloc(1*sizeof(char));

    printf("Introduzca su nombre:");

    while(c = getc(stdin),c!='\n')
    {
        nombre[i] = c;
        i++;
        realloc(nombre,i*sizeof(char));
    }
    nombre[i] = '\0';
    printf("\n");
    return nombre;
}

void menuImprimirMatriz(const int filas, const int columnas, int matriz[filas][columnas], const int cant){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){

            if(matriz[i][j] != cant){
                printf("[%2i] ", matriz[i][j]);
            }else{
                printf("[  ] ");
            };
        }
        printf("\n");
    }
}

void menuTeclas(){
    printf("\nTeclas de juego: a->izquierda, d->derecha, w->arriba, s->abajo, e->salir...\n");
}

const char* menuInicio(const int filas, const int columnas, int matriz[filas][columnas], const int cant){
    const char *nom;

    printf("\n********* Juego de quince *********\n\n");
    printf("Reglas: \n1. Ordenar los numeros en orden ascendente iniciando en la \nprimera casilla y finalizando con el espacio en blanco\n");
    printf("2. El espacio en blanco es el punto de jugada\n");
    printf("3. Puede realizar movimientos sobre la misma fila o columna\n\n");
    nom = menuNombre();
    fflush(stdin);
    menuImprimirMatriz(filas, columnas, matriz, cant);
    menuTeclas();

    return nom;
}

void msjMovInvalido(){
    printf("\nMovimiento invalido\n");
}

void msjGanado(){
    printf("\nFelicidades has ganado\n");
}

void msjPerdido(){
    printf("\nHa Perdido la partida\n");
}

const char menuMovimiento(){
    char caracter; //variable para leer un caracter
    char enter; //variable para leer un enter

    printf("Introduzca su movimiento:");
    caracter = getchar(); //se lee un caracter de entrada por teclado
    enter = getchar(); //se lee un enter de entrada por teclado
    printf("\nHa digitado: %c\n", caracter);

    return caracter;
}
