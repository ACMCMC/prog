#include <stdlib.h>
#include <stdio.h>
/*Se vuelve a definir el tipo de datos que contiene la matriz*/
typedef float TELEMENTO;
/*Implementación del TAD matrizP */
typedef struct
{
    TELEMENTO *datos;      /*valores de la matriz*/
    short nfilas, ncols;   /*tamaño de la matriz (filas, columnas)*/
} STMATRIZ;                /*definición del tipo de datos estructura*/
typedef STMATRIZ *matrizP; /*puntero a estructura*/
/*Funciones de manipulación de datos */
/*Función crear: asigna memoria y devuelve la asignación a la matriz*/
void crear(matrizP *m1, short tamf, short tamc)
{
    long i;
    *m1 = (matrizP)malloc(sizeof(STMATRIZ));
    (*m1)->datos = (TELEMENTO *)malloc(tamf * tamc * sizeof(TELEMENTO));
    (*m1)->nfilas = tamf;
    (*m1)->ncols = tamc;
    for (i = 1; i <= tamf * tamc; i++)
        /*Inicialización a 0 de las componentes de la matriz*/
        *((*m1)->datos + i - 1) = 0;
}
/*Función asignar: Asigna un valor a una posición de la matriz */
void asignar(matrizP *m1, short fila, short columna, TELEMENTO valor)
{
    *((*m1)->datos + (fila - 1) * (*m1)->ncols + columna - 1) = valor;
}

void liberar(matrizP *m1)
{
    if (*m1 != NULL)
    {
        free((*m1)->datos);
        free(*m1);
        *m1 = NULL;
    }
}

TELEMENTO recuperar(matrizP m1, short fila, short columna)
{
    fila--;
    columna--;
    if (m1 != NULL)
    {
        return (*(m1->datos + m1->ncols * fila + columna));
    }
}

short nfilas(matrizP m1)
{
    if (m1 != NULL)
    {
        return (m1->nfilas);
    }
}

short ncolumnas(matrizP m1)
{
    if (m1 != NULL)
    {
        return (m1->ncols);
    }
}

void prodescalar(matrizP *m1, TELEMENTO escalar)
{
    int i, j;
    if (*m1 != NULL)
    {
        for (i = 0; i < nfilas(*m1); i++)
        {
            for (j = 0; j < ncolumnas(*m1); j++)
            {
                *((*m1)->datos + i * ncolumnas(*m1) + j) *= escalar;
            }
        }
    }
    else
    {
        printf("No existe la matriz\n");
    }
}

void inicializar(matrizP *m)
{
    for (int i = 1; i <= nfilas(*m); i++)
    {
        for (int j = 1; j <= ncolumnas(*m); j++)
        {
            asignar(m, i, j, 10.0 * (TELEMENTO)rand() / RAND_MAX);
        }
    }
}

/*void inicializar(matrizP *m) {
    TELEMENTO* element;
    TELEMENTO* fin_mat = (*m)->datos + (ncolumnas(*m))*(nfilas(*m));
    for (element = (*m)->datos; element != fin_mat; element++) {
        *element = 10.0 * (TELEMENTO) rand() / RAND_MAX;
    }
}*/

void trasp(matrizP *result, matrizP m1)
{
    if (ncolumnas(m1) == nfilas(*result) && nfilas(m1) == ncolumnas(*result))
    {
        //las dimensiones son correctas, vamos a trasponer la matriz
        for (int i = 1; i <= nfilas(m1); i++)
        {
            for (int j = 1; j <= ncolumnas(m1); j++)
            {
                asignar(result, j, i, recuperar(m1, i, j));
            }
        }
    }
    else
    {
        printf("Dimensiones incorrectas.\n");
    }
}

void mult(matrizP *result, matrizP m1, matrizP m2)
{
    TELEMENTO prod_acum;
    if (nfilas(m1) == nfilas(*result) && ncolumnas(*result) == ncolumnas(m2) && ncolumnas(m1) == nfilas(m2))
    {
        //los tamaños son correctos, multiplicamos
        for (int i = 1; i <= nfilas(*result); i++)
        {
            for (int j = 1; j <= ncolumnas(*result); j++)
            {
                prod_acum = 0;
                for (int k = 1; k <= ncolumnas(m1); k++)
                {
                    prod_acum += recuperar(m1, i, k) * recuperar(m2, k, j);
                }
                asignar(result, i, j, prod_acum);
            }
        }
    }
    else
    {
        printf("Dimensiones incorrectas.\n");
    }
}