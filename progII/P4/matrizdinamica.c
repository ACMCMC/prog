#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PRECISION 0.1

/*Se vuelve a definir el tipo de datos que contiene la matriz*/
typedef double TELEMENTO; //tener un double nos ayuda a aumentar la precisión
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
    long i;
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
        *m1 = NULL;
    }
}

TELEMENTO recuperar(matrizD m1, short fila, short columna)
{
    fila--;
    columna--;
    if (m1 != NULL)
    {
        return (*(m1->datos + m1->ncols * fila + columna));
    }
}

short nfilas(matrizD m1)
{
    if (m1 != NULL)
    {
        return (m1->nfilas);
    }
}

short ncolumnas(matrizD m1)
{
    if (m1 != NULL)
    {
        return (m1->ncols);
    }
}

void prodescalar(matrizD *m1, TELEMENTO escalar)
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

void inicializar(matrizD *m)
{
    for (int i = 1; i <= nfilas(*m); i++)
    {
        for (int j = 1; j <= ncolumnas(*m); j++)
        {
            asignar(m, i, j, 10.0 * (TELEMENTO)rand() / RAND_MAX);
        }
    }
}

/*void inicializar(matrizD *m) {
    TELEMENTO* element;
    TELEMENTO* fin_mat = (*m)->datos + (ncolumnas(*m))*(nfilas(*m));
    for (element = (*m)->datos; element != fin_mat; element++) {
        *element = 10.0 * (TELEMENTO) rand() / RAND_MAX;
    }
}*/

void trasp(matrizD *result, matrizD m1)
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

void mult(matrizD *result, matrizD m1, matrizD m2)
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

void suma(matrizD *result, matrizD A, matrizD B)
{
    int i, j;
    if (nfilas(A) == nfilas(B) && nfilas(B) == nfilas(*result) && ncolumnas(A) == ncolumnas(B) && ncolumnas(B) == ncolumnas(*result))
    {
        for (i = 1; i <= nfilas(*result); i++)
        {
            for (j = 1; j <= ncolumnas(*result); j++)
            {
                asignar(result, i, j, recuperar(A, i, j) + recuperar(B, i, j));
            }
        }
    }
}

void inicializarSubMatriz(matrizD *submatriz, matrizD original, int cuadrante)
{
    int i, j, i_orig, j_orig, /*imax, jmax,*/ j_inic;

    if (nfilas(original) / 2 == nfilas(*submatriz) && ncolumnas(original) / 2 == ncolumnas(*submatriz) && nfilas(original) == ncolumnas(original) && cuadrante > 0 && cuadrante <= 4)
    {
        //printf("Cuadrante %d, Resultado: %d\n",cuadrante, cuadrante & 1);
        if (cuadrante & 1)
        {
            //es el cuadrante 1 o el 3, la columna tiene que empezar en 1
            j_inic = 1;
            //jmax = ncolumnas(original)/2;
            //printf("Cuadrante 1 o 3\n");
        }
        else
        {
            //es el cuadrante 2 o el 4, tiene que empezar en ncolumnas/2 + 1
            j_inic = ncolumnas(original) / 2 + 1;
            //jmax = ncolumnas(original);
        }
        if (cuadrante <= 2)
        {
            //j empezará al principio de la matriz
            i_orig = 1;
            //imax = nfilas(original)/2;
        }
        else
        {
            //j empezará en la mitad
            i_orig = nfilas(original) / 2 + 1;
            //imax = nfilas(original);
        }

        i = 1;
        j = 1;

        //printf("i_orig vale %d, j_orig vale %d\n",i_orig,j_orig);

        while (i <= (nfilas(original) / 2))
        {
            j = 1;
            j_orig = j_inic;
            while (j <= (ncolumnas(original) / 2))
            {
                //printf("Asignando a [%d,%d] [%d,%d]: %f\n",i,j,i_orig,j_orig,recuperar(original, i_orig, j_orig));
                asignar(submatriz, i, j, recuperar(original, i_orig, j_orig));
                j_orig++;
                j++;
            }
            i++;
            i_orig++;
        }
    }
    else
    {
        printf("Tamanos erroneos o cuadrante erroneo\n");
    }
}

void mult_divide_venceras(matrizD *result, matrizD A, matrizD B)
{
    int i, j, cuadrante_a, cuadrante_b, i_suma;
    matrizD *array_matA;
    matrizD *array_matB;
    matrizD *array_matRes;
    matrizD *array_matResParc;

    if (A != NULL && B != NULL && result != NULL && *result != NULL) {

    if (ncolumnas(A) == ncolumnas(B) && ncolumnas(B) == ncolumnas(*result) && ncolumnas(A) == nfilas(A) && nfilas(A) == nfilas(B) && nfilas(B) == nfilas(*result) && (ncolumnas(A) & ncolumnas(A) - 1) == 0)
    {
        //todo correcto. Se cumple que son matrices cuadradas del mismo tamaño. y potencia de 2
        if (ncolumnas(A) <= 2)
        {
            mult(result, A, B);
        }
        else
        {
            //Divide y vencerás
            //Creamos 8 matrices de tamaño n/2, los cuadrantes de a y b
            array_matA = (matrizD *)malloc(sizeof(*array_matA) * 4);
            array_matB = (matrizD *)malloc(sizeof(*array_matB) * 4);
            array_matResParc = (matrizD *)malloc(sizeof(*array_matResParc) * 8);
            array_matRes = (matrizD *)malloc(sizeof(*array_matRes) * 4);
            for (i = 0; i < 4; i++)
            {
                crear(array_matA + i, nfilas(A) / 2, ncolumnas(A) / 2);
                crear(array_matB + i, nfilas(B) / 2, ncolumnas(B) / 2);
                inicializarSubMatriz(array_matA + i, A, i + 1);
                inicializarSubMatriz(array_matB + i, B, i + 1);
                crear(array_matResParc + 2 * i, nfilas(A) / 2, ncolumnas(A) / 2);
                crear(array_matResParc + 2 * i + 1, nfilas(A) / 2, ncolumnas(A) / 2);
                crear(array_matRes + i, nfilas(A) / 2, ncolumnas(A) / 2);

                //printf("Imprimiendo la submatriz: %d\n", i + 1);
                /*for (int elem_i = 1; elem_i <= nfilas(array_matA[i]); elem_i++)
                {
                    for (int j = 1; j <= ncolumnas(array_matA[i]); j++)
                    {
                        printf("%f\t", recuperar(array_matA[i], elem_i, j));
                    }
                    printf("\n");
                }*/
            }

            for (cuadrante_a = 0; cuadrante_a <= 2; cuadrante_a += 2)
            {
                for (cuadrante_b = 0; cuadrante_b <= 1; cuadrante_b++)
                {
                    //Hacemos recursivamente esta funcion para multiplicar los cuadrantes que requiere el algoritmo
                    mult_divide_venceras(array_matResParc + ((2 * cuadrante_a) + (2 * cuadrante_b)), array_matA[cuadrante_a], array_matB[cuadrante_b]);
                    mult_divide_venceras(array_matResParc + ((2 * cuadrante_a) + (2 * cuadrante_b) + 1), array_matA[cuadrante_a + 1], array_matB[cuadrante_b + 2]);
                }
            }

            //Liberamos las matrices de los cuadrantes de a y b
            for (i = 0; i < 4; i++)
            {
                liberar(array_matA + i);
                liberar(array_matB + i);
            }
            free(array_matA);
            free(array_matB);

            for (i_suma = 0; i_suma < 4; i_suma++)
            {
                //De la matriz de resultados parciales, sumamos cada dos resultados adyacentes y lo guardamos en la matriz de matrices de resultados
                suma(array_matRes + i_suma, array_matResParc[i_suma * 2], array_matResParc[i_suma * 2 + 1]);
                liberar(array_matResParc + (i_suma * 2));
                array_matResParc[i_suma * 2] = NULL; //No es necesario en este caso, porque no lo vamos a volver a usar, pero es buena practica
                liberar(array_matResParc + ((i_suma * 2) + 1));
                array_matResParc[(i_suma * 2) + 1] = NULL;
            }
            free(array_matResParc);

            for (i_suma = 0; i_suma < 4; i_suma++)
            {
                //Asignamos cada matriz de resultados al cuadrante correspondiente
                for (i = 1; i <= nfilas(array_matRes[i_suma]); i++)
                {
                    for (j = 1; j <= ncolumnas(array_matRes[i_suma]); j++)
                    {
                        asignar(result, i + ((i_suma >= 2) ? nfilas(*result) / 2 : 0), j + ((i_suma & 1) ? ncolumnas(*result) / 2 : 0), recuperar(array_matRes[i_suma], i, j));
                    }
                }
                liberar(array_matRes + i_suma);
                array_matRes[i_suma] = NULL;
            }
            free(array_matRes);
        }
    }
    else
    {
        printf("No son matrices cuadradas del mismo tamano\n");
    }
    } else {
        printf("Las matrices no están creadas, o el puntero del resultado está establecido a NULL\n");
    }
}

int matricesIguales(matrizD m1, matrizD m2)
{
    int i, j;
    if (m1 != NULL && m2 != NULL)
    {
        if (nfilas(m1) == nfilas(m2) && ncolumnas(m1) == ncolumnas(m2))
        {
            for (i = 1; i <= nfilas(m1); i++)
            {
                for (j = 1; j <= ncolumnas(m1); j++)
                {
                    if (fabs(recuperar(m1, i, j) - recuperar(m2, i, j)) > PRECISION)
                    {
                        return 0; //Hay un elemento diferente
                    }
                }
            }
            return 1; //Las matrices son iguales
        }
        else
        {
            return 0; //Las matrices no tienen igual tamaño => Son distintas
        }
    }
    else
    {
        printf("Las matrices no estan creadas\n");
        return 0;
    }
}