/*Autor: Aldán Creo Mariño
Data: 28 de outubro de 2019
Versión: 1
Este programa traballa con polinomios de ata grao 5*/

#define EXIT_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int grao;
    int coe[6];
} t_polinomio;

void Crea(int grao, int coe[], t_polinomio *pol)
{
    pol->grao = grao;
    for (int i = grao; i >= 0; i--)
    {
        pol->coe[i] = coe[i];
    }
}

double Avaliar(t_polinomio pol, double pt)
{
    double valor = 0;
    for (int i = 0; pol.grao >= i; i++)
    {
        valor = valor + (pol.coe[i] * pow(pt, i));
    }
    return (valor);
}

void Mostrar(t_polinomio pol)
{
    printf("%d*x^%d ", pol.coe[pol.grao], pol.grao);
    for (int i = pol.grao - 1; i >= 0; i--)
    {
        printf("+ %d*x^%d ", pol.coe[i], i);
    }
    printf("\n");
}

void Derivar(t_polinomio pol, t_polinomio *der)
{
    der->grao = pol.grao - 1;
    for (int i = 1; i <= pol.grao; i++)
    {
        der->coe[i - 1] = pol.coe[i] * i;
    }
}

int main(int argc, char **argv)
{
    int coe[6], grao;
    printf("Introduza o grao do polinomio: ");
    scanf("%d", &grao);
    printf("\nIntroduza os valores dos coeficientes:\n");
    for (int i = 0; i <= grao; i++)
    {
        printf("Coeficiente %d: ", i);
        scanf("%d", &coe[i]);
    }
    t_polinomio miPolinomio;
    Crea(grao, coe, &miPolinomio);
    printf("\nO polinomio orixinal e:\n");
    Mostrar(miPolinomio);
    printf("\nO polinomio derivado e:\n");
    t_polinomio der;
    Derivar(miPolinomio, &der);
    Mostrar(der);

    int x = 0;
    printf("\nIntroduza o valor da x para avaliar o polinomio: ");
    scanf("%d", &x);

    int aval = Avaliar(miPolinomio, x);

    printf("\nCando x = %d, o polinomio vale: %d",x,aval);

    return (EXIT_SUCCESS);
}
