//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//

#include "juego.h"

int main () {

    archivo = fopen("jugadores.txt", "a+");
    char caracter; //variable para leer un caracter
    char enter; //variable para leer un enter
    srand( time(NULL) * getpid() );
    llenarMatriz();
    posicionActual();
    printf("Introduzca su nombre:");
    scanf("%s", player.name);
    //fgets(player.name, sizeof(player.name), stdin);
    fflush(stdin);
    //player.cantMovs = 0;
    imprimirMatriz(matriz);
    printf("Teclas de juego: a->izquierda, d->derecha, w->arriba, s->abajo, e->salir...\n");
    do{
        printf("Introduzca su movimiento:");
        caracter = getchar(); //se lee un caracter de entrada por teclado
        enter = getchar(); //se lee un enter de entrada por teclado
        printf("\nHa digitado: %c\n", caracter);
        if(caracter == 'w' || caracter == 's' || caracter == 'd' || caracter == 'a'){
            if(jugada((int)caracter)){
                imprimirMatriz(matriz);
                ganar();
                fflush(stdin);
            }
            else{
                msjMovInvalido();
                imprimirMatriz(matriz);
            }
            player.cantMovs++;
        }
        else if(caracter == 'e'){
            printf("Saliendo...\n");
        }
        else{
            msjMovInvalido();
        }
    }while(caracter != 'e');

    printf("name: %s\n", player.name);
    printf("movs: %d\n", player.cantMovs);

    guardarMarcador(archivo);
    fclose(archivo);


    return 0;
}
