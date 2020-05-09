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

int main(int argc, char** argv) {
    matrizD a;
    //crear(&a,4,4);
    //inicializar(&a);
    matrizD b;
    //crear(&b,4,4);
    //inicializar(&b);

    int nfil, ncol;

    if ((argc > 3) && ((argc - 3) == (atoi(argv[1])) * (atoi(argv[2]))))
            {
                nfil = atoi(argv[1]);
                ncol = atoi(argv[2]);
                crear(&a, nfil, ncol);
                for (int i = 1; i <= nfil; i++)
                {
                    for (int j = 1; j <= ncol; j++)
                    {
                        asignar(&a, i, j, atoi(argv[(i - 1) * (ncol) + j + 2]));
                    }
                }
            }

            if ((argc > 3) && ((argc - 3) == (atoi(argv[1])) * (atoi(argv[2]))))
            {
                nfil = atoi(argv[1]);
                ncol = atoi(argv[2]);
                crear(&b, nfil, ncol);
                for (int i = 1; i <= nfil; i++)
                {
                    for (int j = 1; j <= ncol; j++)
                    {
                        asignar(&b, i, j, atoi(argv[(i - 1) * (ncol) + j + 2]));
                    }
                }
            }

    printf("Matriz A:\n");
    imprimir(a);
    printf("Matriz B:\n");
    imprimir(b);
    matrizD result;
    crear(&result,4,4);
    printf("Matriz resultado:\n");
    mult_divide_venceras(&result,a,b);
    imprimir(result);
}