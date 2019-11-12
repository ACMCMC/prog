/*ENUNCIADO

Escribir unha función que reciba dúas cadeas de caracteres e devolva outra cadea de caracteres que conteña unicamente os caracteres comúns; de non habelos debe devolver un punteiro a NULL. O prototipo da función debe ser:

    char * CarCompartidos(char *cad1, char *cad2);

Lembrade que a cadea devolta debe levar o carácter de fin de cadea.*/

/*Autor: Aldán Creo Mariño
Data: 10 de novembro de 2019
Versión: 1
Este programa elabora unha cadea de caracteres que contén só os comúns a outras dúas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EXIT_SUCCESS 0

char *Ordear(char *cadea)
{
    char caracter_swap;
    char *cadea_ordeada = (char *)malloc(sizeof(*cadea) * (strlen(cadea) + 1));
    int correcto, i;

    strcpy(cadea_ordeada, cadea);

    do
    {
        correcto = 1;
        for (i = 1; cadea_ordeada[i] != '\0'; i++)
        {
            if (cadea_ordeada[i] < cadea_ordeada[i - 1])
            {
                caracter_swap = cadea_ordeada[i - 1];
                cadea_ordeada[i - 1] = cadea_ordeada[i];
                cadea_ordeada[i] = caracter_swap;
                correcto = 0;
            }
        }
    } while (!correcto);

    int shift = 0;

    for (i = 1; cadea_ordeada[i] != '\0'; i++)
    {

        if (cadea_ordeada[i] == cadea_ordeada[i - 1])
        {
            shift++;
        }
        else
        {
            cadea_ordeada[i - shift] = cadea_ordeada[i];
        }
    }

    cadea_ordeada[i - shift] = '\0';

    return (cadea_ordeada);
}

char *CarCompartidos(char *cad1, char *cad2)
{
    char *cad1_ord = Ordear(cad1);
    char *cad2_ord = Ordear(cad2);

    char *cad_res = (char *)malloc(0);
    char *cad_busqueda, *caracter_act;
    int i, long_cad_res = 0;
    for (caracter_act = cad1_ord; *caracter_act != '\0'; caracter_act++)
    {
        int mitad_cadea = (ceil(((double)strlen(cad2_ord)) / ((double)2)));

        cad_busqueda = (char *)malloc(sizeof(*cad2_ord) * strlen(cad2_ord)); //creamos unha nova cadea de tamaño a metade da cadea 2

        strcpy(cad_busqueda, cad2_ord);

        while (strlen(cad_busqueda) > 1)
        {
            mitad_cadea = (ceil(((double)strlen(cad_busqueda)) / ((double)2)));

            if (*caracter_act > cad_busqueda[mitad_cadea])
            {
                for (i = 0; i < mitad_cadea + 1; i++)
                {
                    cad_busqueda[i] = cad_busqueda[mitad_cadea + i];
                }
            }
            cad_busqueda = realloc(cad_busqueda, sizeof(*cad2_ord) * (mitad_cadea + 1));

            cad_busqueda[mitad_cadea] = '\0';
        }

        if (*cad_busqueda == *caracter_act)
        {
            long_cad_res++;
            cad_res = realloc(cad_res, sizeof(*cad_res) * long_cad_res);
            cad_res[long_cad_res - 1] = *cad_busqueda;
        }
    }

    long_cad_res++;
    cad_res = realloc(cad_res, sizeof(*cad_res) * long_cad_res);
    cad_res[long_cad_res - 1] = '\0';

    return (cad_res);
}

int main()
{

    printf("Iniciando busqueda...\n");
    printf("\n%s", CarCompartidos("dccccbaaaui","adasd"));
    printf("\nFin da busqueda.");

    return (EXIT_SUCCESS);
}