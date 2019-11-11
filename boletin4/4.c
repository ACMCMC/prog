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
    char *cad_res;
    while((*cad1 != '\0') && (*cad2 != '\0')) {
        if(*cad1 == *cad2) {
            printf("%c",*cad1);
        }
        cad1++;
        cad2++;
    }
}

int main() {

    CarCompartidos("Holaaa","Arbol");

    return(EXIT_SUCCESS);
}