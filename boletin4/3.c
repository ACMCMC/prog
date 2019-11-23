/*ENUNCIADO

Escribir unha función int *PosNegativo(int *vector) que reciba un vector de enteiros e devolva mediante un punteiro a posición do primeiro valor negativo. Dende a función main() hai que imprimir o valor na posición devolta pola función no caso de que haxa algún valor negativo no vector, senón debe amosar unha mensaxe indicando que o vector non ten valores negativos.*/

/*Autor: Aldán Creo Mariño
Data: 10 de novembro de 2019
Versión: 1
Este programa busca o primeiro valor negativo nun vector de enteiros*/

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

int *posNegativo(int *vector, int lonx) //Esta función devolve un punteiro ao primeiro elemento negativo do vector
{
    int *i = vector;
    printf("\n\nIniciando busqueda:\n");//Iso é prescindible, son datos técnicos sobre a búsqueda
    printf("Buscarase dende a posicion de memoria %p ata a %p, con incrementos de %d.\n\n", vector, vector + sizeof(vector) * lonx, sizeof(vector));
    printf("Iteracion\tDireccion\tIndice\t\t\t\tValor\n");

    while (*i >= 0 && ((sizeof(vector) * lonx) > ((i - vector) * sizeof(vector))))
    {
        printf("\n%d", i - vector + 1);
        printf("\t\t%d", (i - vector));
        printf("\t\t%p", i);
        printf("\t\t%d", *i);
        i++; //Incrementamos o punteiro, agora apunta ao seguinte elemento
    }

    if (*i < 0)
    {
        return i; //Devolvemos o punteiro, que apunta ao primeiro elemento negativo
    }
    else
    {
        return NULL; //Se non atopamos un elemento negativo, devolvemos NULL
    }
}

int main()
{
    int *vector,lonx_vec;
    printf("Introduza a lonxitude do vector: ");
    scanf("%d",&lonx_vec);
    for (int i = 0; i < lonx_vec; i++) //Lemos os datos do vector
    {
        printf("Introduza o valor do elemento %d (en 0x%p): ", i + 1, &vector[i]);
        scanf("%d", &vector[i]);
    }

    int *posNeg = posNegativo(vector, lonx_vec); //Gardamos o punteiro o primeiro elemento negativo da cadea

    if (posNeg != NULL)
    {
        printf("\n\nO valor gardado en 0x%p e %d\n", posNeg, *posNeg); //Imprimimos o valor e o punteiro
    }
    else //Se o punteiro e nulo, enton mostramos erro
    {
        printf("\n\nNon se atopou ningun negativo no vector\n");
    }

    return (EXIT_SUCCESS);
}