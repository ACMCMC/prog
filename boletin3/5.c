/*ENUNCIADO

Escribir un programa cunha función que determine a media dos valores dunha secuencia de
enteiros almacenada nun arquivo. Lede os datos do arquivo e ideos gardando nun vector. Facede a
lectura ata chegar ao final o arquivo (nese momento feof(ptf)!=0). No arquivo cabeceira stdlib.h
está definida a función de formato int feof(FILE *ptf), que ten coma argumento o punteiro a arquivo
e devolve un valor distinto de cero cando chega ao final do arquivo e cero noutro caso.*/

/*Autor: Aldán Creo Mariño
Data: 28 de outubro de 2019
Versión: 1
Este programa determina a media dos valores dunha secuencia de enteiros almacenados nun arquivo*/

#define EXIT_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *arch;
  if(arch = fopen("arquivo.txt","r") != NULL) {
    printf("Erro abrindo o arquivo");
    return(1);
  }
  fscanf(arch,);
  
  return(EXIT_SUCCESS);
}
