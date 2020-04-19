#define EXIT_SUCCESS 0;
#include "matrizdinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    matrizP mat;
    matrizP mat_trasp;
    int i, j;

    printf("Introduzca dimensiones (filas columnas): ");
    scanf(" %d %d", &i, &j);

    crear(&mat, i, j);
    crear(&mat_trasp, j, i);

    inicializar(&mat);

    //printf("Filas: %d, Columnas: %d\n", nfilas(mat), ncolumnas(mat));

    printf("( ");
    for (i = 1; i <= nfilas(mat); i++) {
        for (j = 1; j <= ncolumnas(mat); j++) {
            printf("%f ", recuperar(mat, i, j));
        }
        printf(")\n( ");
    }

        printf("\n\nMatriz traspuesta:\n");
    trasp(&mat_trasp, mat);

    printf("( ");
    for (i = 1; i <= nfilas(mat_trasp); i++) {
        for (j = 1; j <= ncolumnas(mat_trasp); j++) {
            printf("%f ", recuperar(mat_trasp, i, j));
        }
        printf(")\n( ");
    }

    return EXIT_SUCCESS;
}