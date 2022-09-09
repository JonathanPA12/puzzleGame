//
// Created by: Mauren Miranda Q - Jonathan Pineda A
//

#include <time.h>
#include "juego.h"
#include "menu.h"


int main () {

    archivo = fopen("jugadores.txt", "a+");
    char caracter; //variable para leer un caracter

    srand( time(NULL) * getpid() );
    iniciar();
    player.name = menuInicio(FILAS, COLUMNAS, matriz, CANT);//scanf("%s", player.name); //fgets(player.name, sizeof(player.name), stdin);

    do{
        caracter = menuMovimiento();
        if(caracter == 'w' || caracter == 's' || caracter == 'd' || caracter == 'a'){
            if(jugada((int)caracter)){
                if(ganar()){
                    strcpy(player.gano, "Si");
                    msjGanado();
                    caracter = 'e';
                }
                menuImprimirMatriz(FILAS, COLUMNAS, matriz, CANT);
                fflush(stdin);
            }
            else{
                msjMovInvalido();
                menuImprimirMatriz(FILAS, COLUMNAS, matriz, CANT);
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

    if(!ganar()){
        strcpy(player.gano, "No");
        msjPerdido();
    }

    printf("name: %s\n", player.name);
    printf("movs: %d\n", player.cantMovs);

    guardarMarcador(archivo);
    fclose(archivo);

    free((char*)player.name); // se libera el ptrn de la struct

    return 0;
}
