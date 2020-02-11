#include "matrizdinamica.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    char opcion = 0;
    matrizD m1;
    unsigned short nfils, ncols;
    int i, j;

    printf("a) Crear matriz m1\ns) Salir\nSelecciona a túa opción: ");
    do {
        scanf("%c", &opcion);
    } while (!(opcion == 'a' || opcion == 's'));

    if (opcion == 'a')
    {
        printf("Creando matriz...\n");
        printf("Introduza numero de filas e de columnas: \n");
        scanf("%d %d", &nfils, &ncols);

        crear(&m1, nfils, ncols);

        for (i = 0; i < nfils; i++) {
        for (i = 0; i < nfils; i++) {

        }
        }
    }

    return (EXIT_SUCCESS);
}