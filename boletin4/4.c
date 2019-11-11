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

char * CarCompartidos(char *cad1, char *cad2) {
    char *cad_res = (char *)malloc(sizeof(char));
    int cuenta = 0;
    while((*cad1 != '\0') && (*cad2 != '\0')) {
        if(*cad1 == *cad2) {
            printf("\n%c",*cad1);
            cuenta++;
            cad_res = realloc(cad_res,cuenta*sizeof(char));
        }
        cad1++;
        cad2++;
    }
    cad_res = realloc(cad_res,(cuenta+1)*sizeof(char));
    cad_res[cuenta] = '\0';
    return(cad_res);
}

int main() {

    printf("Iniciando busqueda...");
    printf("\n%s",CarCompartidos("Holaaa","Aorbal"));
    printf("\nFin da busqueda.");

    return(EXIT_SUCCESS);
}