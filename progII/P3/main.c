#define EXIT_SUCCESS 0;
#include "matrizdinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    matrizP mat;

    crear(&mat, 5, 5);

    inicializar(&mat);

    printf("Filas: %d, Columnas: %d\n", nfilas(mat), ncolumnas(mat));

    printf("( ");
    for (int i = 1; i <= nfilas(mat); i++) {
        for (int j = 1; j <= ncolumnas(mat); j++) {
            printf("%f ", recuperar(&mat, i, j));
        }
        printf(")\n( ");
    }

    return EXIT_SUCCESS;
}