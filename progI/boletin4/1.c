/*ENUNCIADO

Escribir un programa que declare e inicie (á calquera valor que queirades) un double, un int, e unha cadea. O voso programa entón terá que imprimir o enderezo e o valor almacenado en cada un das variables. Utilizar o especificador de formato "%p" para imprimir os enderezos en notación hexadecimal (base 16). Veredes enderezos algo así como: 0xbfe55918. Os caracteres iniciais 0x indican notación hexadecimal e o resto dos díxitos dan o enderezo. */

/*Autor: Aldán Creo Mariño
Data: 10 de novembro de 2019
Versión: 1
Este programa realiza operacións básicas con direccións de memoria*/

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

int main()
{
    double a = 3.1415;
    int b = 1492;
    char c[] = "Hola";

    printf("%lf esta gardado en %p\n", a, &a);
    printf("%d esta gardado en %p\n", b, &b);
    printf("%s esta gardado no rango %p - %p\n", c, c, c + strlen(c));

    return (EXIT_SUCCESS);
}