#include <stdlib.h>
#include <stdio.h>
/*Se vuelve a definir el tipo de datos que contiene la matriz*/
typedef float TELEMENTO;
/*Implementación del TAD matrizD */
typedef struct
{
    TELEMENTO *datos;      /*valores de la matriz*/
    short nfilas, ncols;   /*tamaño de la matriz (filas, columnas)*/
} STMATRIZ;                /*definición del tipo de datos estructura*/
typedef STMATRIZ *matrizD; /*puntero a estructura*/
/*Funciones de manipulación de datos */
/*Función crear: asigna memoria y devuelve la asignación a la matriz*/
void crear(matrizD *m1, short tamf, short tamc)
{
    short i;
    *m1 = (matrizD)malloc(sizeof(STMATRIZ));
    (*m1)->datos = (TELEMENTO *)malloc(tamf * tamc * sizeof(TELEMENTO));
    (*m1)->nfilas = tamf;
    (*m1)->ncols = tamc;
    for (i = 1; i <= tamf * tamc; i++)
        /*Inicialización a 0 de las componentes de la matriz*/
        *((*m1)->datos + i - 1) = 0;
}
/*Función asignar: Asigna un valor a una posición de la matriz */
void asignar(matrizD *m1, short fila, short columna, TELEMENTO valor)
{
    *((*m1)->datos + (fila - 1) * (*m1)->ncols + columna - 1) = valor;
}

void liberar(matrizD *m1)
{
    if (*m1 != NULL)
    {
        free((*m1)->datos);
        free(*m1);
        *m1 == NULL;
    }
}

TELEMENTO recuperar(matrizD *m1, short fila, short columna)
{
    fila--;
    columna--;
    if (*m1 != NULL)
    {
        return (*((*m1)->datos + (*m1)->ncols * fila + columna));
    }
}

short nfilas(matrizD *m1)
{
    if (*m1 != NULL)
    {
        return ((*m1)->nfilas);
    }
}

short ncolumnas(matrizD *m1)
{
    if (*m1 != NULL)
    {
        return ((*m1)->ncols);
    }
}

void prodescalar(matrizD *m1, TELEMENTO escalar)
{
    int i, j;
    if (*m1 != NULL)
    {
        for (i = 0; i < nfilas(m1); i++)
        {
            for (j = 0; j < ncolumnas(m1); j++)
            {
                *((*m1)->datos + i * ncolumnas(m1) + j) *= escalar;
            }
        }
    }
}