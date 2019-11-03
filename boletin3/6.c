/*ENUNCIADO

Escribir un programa que lea un arquivo de texto e que garde noutro arquivo ese texto encriptado
da seguinte forma: o primeiro carácter imprímeo tal como foi lido, nos demais casos, cada carácter é
substituído polo carácter na posición da táboa ASCII que corresponde ao módulo 128 da suma do
código ASCII do carácter actual máis o do carácter lido previamente. Exemplo: Se tivésemos no
arquivo orixe:
35 Abacates
entón debe aparecer no arquivo de saída:
3hUa#CDDUYX
Empregar unha función para o encriptado.*/

/*Autor: Aldán Creo Mariño
Data: 28 de outubro de 2019
Versión: 1
Este programa traballa con datos encriptados*/

#define EXIT_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encriptar(char *string, char *encriptado) {

  encriptado[0] = string[0];

  for (int i = 1; i < strlen(string) ; i++)
  {
    encriptado[i] = (string[i] + string[i-1]) % 128;
  }
  encriptado[strlen(string)] = '\0';
}

int main(){

  char string[100] = "35 Abacates", encriptado[100];
  FILE *arch;

  if ((arch = fopen("encriptado.txt","w")) == NULL) {
    printf("Erro de apertura do arquivo.");
    exit(1);
  }

  encriptar(string,encriptado);

  printf("%s, %d caracteres\n",string,strlen(string));
  printf("%s",encriptado);
  
  fprintf(arch,"%s",encriptado);

  return(EXIT_SUCCESS);
}
