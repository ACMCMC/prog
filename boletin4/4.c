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

#define EXIT_SUCCESS 0

char *CarCompartidos(char *cad1, char *cad2)
{
    char *cad_res = (char *)malloc(0);

    int cuenta = 0, shift = 0, correcto, i;

    do {
    correcto = 1;
    for(i = 1; cad1[i] != '\0'; i++) {
        if(cad1[i] < cad1[i-1]) {
            cad1[i-shift] = cad1[i-1];
            cad1[i-shift-1] = cad1[i];
            correcto = 0;
        } else if (cad1[i] == cad1[i-1]) {
            
            shift++;
        } else {
            cad1_ord[i-shift] = cad1[i];
        }
    }
    } while(!correcto);

    printf("%s",cad1);

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

    printf("Iniciando busqueda...");
    printf("\n%s", CarCompartidos("dcba", "Troal"));
    printf("\nFin da busqueda.");

    return (EXIT_SUCCESS);
}