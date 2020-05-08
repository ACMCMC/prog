#include <stdlib.h>
#include <stdio.h>
#include "matrizdinamica.h"

void imprimir(matrizD m1)
{
    int i, j;
    if (m1 != NULL)
    {
        for (i = 1; i <= nfilas(m1); i++)
        {
            for (j = 1; j <= ncolumnas(m1); j++)
            {
                printf("%f\t", recuperar(m1, i, j));
            }
            printf("\n");
        }
    }
}

int main() {
    matrizD a;
    crear(&a,4,4);
    inicializar(&a);
    printf("Matriz A:\n");
    imprimir(a);
    matrizD b;
    crear(&b,4,4);
    inicializar(&b);
    printf("Matriz B:\n");
    imprimir(b);
    matrizD result;
    crear(&result,4,4);
    printf("Matriz resultado:\n");
    mult_divide_venceras(&result,a,b);
}