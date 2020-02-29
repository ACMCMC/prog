#include <stdlib.h>
#include <stdio.h>
#include "matrizdinamica.h"

void imprimir(matrizD *m1)
{
    int i, j;
    for (i = 1; i <= nfilas(m1); i++)
    {
        for (j = 1; j <= ncolumnas(m1); j++)
        {
            printf("%f\t", recuperar(m1, i, j));
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    matrizD m1;             /* declaramos la matriz*/
    short nfil, ncol, i, j; /*variables tamaño y recorrido */
    TELEMENTO valor;        /*El valor a introducir en la matriz*/
    char opcion;            /*La variable del menú*/
    do
    {
        printf("\n--------------------\n");
        printf("\na) Crear matriz m1");
        printf("\nl) Liberar matriz m1");
        printf("\nr) Recuperar elemento");
        printf("\ns) Salir");
        printf("\n--------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a': /*Crear matriz m1*/
            /*Asignar valores a m1*/

            //Si se ha pasado como argumento por la linea de comandos, no se piden los valores
            if ((argc > 3) && ((argc - 3) == (atoi(argv[1])) * (atoi(argv[2]))))
            {
                nfil = atoi(argv[1]);
                ncol = atoi(argv[2]);
                crear(&m1, nfil, ncol);
                for (i = 1; i <= nfil; i++)
                {
                    for (j = 1; j <= ncol; j++)
                    {
                        asignar(&m1, i, j, atoi(argv[(i - 1) * (ncol) + j + 2]));
                    }
                }
            }
            else
            {
                printf("Tamanho de la matriz m1 (filas columnas): ");
                scanf("%hd %hd", &nfil, &ncol);
                crear(&m1, nfil, ncol);
                for (i = 1; i <= nfil; i++)
                {
                    for (j = 1; j <= ncol; j++)
                    {
                        printf("m1(%d,%d): ", i, j);
                        scanf("%f", &valor);
                        asignar(&m1, i, j, valor);
                    }
                }
            }
            imprimir(&m1);
            break;
        case 'l':
            liberar(&m1);
            break;
        case 'r':
            printf("Introduzca las coordenadas del elemento (fila) (columna): ");
            scanf("%hd %hd", &nfil, &ncol);
            printf("Valor: %f\n", recuperar(&m1, nfil, ncol));
            break;
        case 's':
            printf("Saliendo del programa\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    } while (opcion != 's');
    return (EXIT_SUCCESS);
}