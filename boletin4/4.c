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

#define EXIT_SUCCESS 0

char *Ordear(char *cadea)
{
    char caracter_swap;
    char *cadea_ordeada = (char *)malloc(sizeof(*cadea)*(strlen(cadea) + 1));
    int correcto, i;

    strcpy(cadea_ordeada,cadea);

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

    cadea_ordeada[i-shift] = '\0';

    return (cadea_ordeada);
}

char *CarCompartidos(char *cad1, char *cad2)
{
    char *cad_res = (char *)malloc(0);

    int cuenta = 0, shift = 0, correcto, i;

    do
    {
        correcto = 1;
        for (i = 1; cad1[i] != '\0'; i++)
        {
            if (cad1[i] < cad1[i - 1])
            {
                cad1[i - shift] = cad1[i - 1];
                cad1[i - shift - 1] = cad1[i];
                correcto = 0;
            }
            else if (cad1[i] == cad1[i - 1])
            {

                shift++;
            }
            else
            {
                cad1[i - shift] = cad1[i];
            }
        }
    } while (!correcto);

    printf("%s", cad1);

    while ((*cad1 != '\0') && (*cad2 != '\0'))
    {
        if (*cad1 == *cad2)
        {
            cuenta++;
            cad_res = realloc(cad_res, cuenta * sizeof(char));
            cad_res[cuenta - 1] = *cad1;
        }
        cad1 += sizeof(char);
        cad2 += sizeof(char);
    }
    cad_res = realloc(cad_res, (cuenta + 1) * sizeof(char));
    cad_res[cuenta] = '\0';

    return (cad_res);
}

int main()
{

    printf("Iniciando busqueda...\n");
    printf("\n%s", Ordear("dcbaaaui"));
    printf("\nFin da busqueda.");

    return (EXIT_SUCCESS);
}