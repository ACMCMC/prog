#include <stdlib.h>
#include <stdio.h>
#include "matrizdinamica.h"
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
        printf("\ns) Salir");
        printf("\n--------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a': /*Crear matriz m1*/
            printf("Tamanho de la matriz m1 (filas columnas): ");
            scanf("%hd %hd", &nfil, &ncol);
            crear(&m1, nfil, ncol);
            /*Asignar valores a m1*/
            for (i = 1; i <= nfil; i++)
            {
                for (j = 1; j <= ncol; j++)
                {
                    printf("m1(%d,%d): ", i, j);
                    scanf("%f", &valor);
                    asignar(&m1, i, j, valor);
                }
            }
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