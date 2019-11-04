/*ENUNCIADO

Escribir un programa que lea un texto almacenado nun arquivo, encriptado de acordo ca técnica
descrita antes, descifre tal texto e o presente descifrado por pantalla. Empregar unha función para o
desencriptado. Para desencriptar hai que sumarlle 128 á resta de códigos e despois cacular o
módulo 128*/

/*Autor: Aldán Creo Mariño
Data: 28 de outubro de 2019
Versión: 1
Este programa traballa con datos encriptados*/

#define EXIT_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_aldan.h"

void desencriptar(char *encriptado, char *desencriptado) {

  desencriptado[0] = encriptado[0];

  for (int i = 1; i < strlen(encriptado) ; i++)
  {
    desencriptado[i] = (encriptado[i] - desencriptado[i-1] + 128) % 128;
  }
  desencriptado[strlen(encriptado)] = '\0';
}

int main(){

  char encriptado[100], desencriptado[100];
  FILE *arch, *arch_saida;

  if (((arch = fopen("encriptado.txt","r")) == NULL) ||
  ((arch_saida = fopen("desencriptado.txt","w")) == NULL)) {
    printf("Erro de apertura do arquivo.");
    exit(1);
  }

  fgets(encriptado,100,arch);
  
  printf("%s, %d caracteres\n",encriptado,strlen(encriptado));

  desencriptar(encriptado,desencriptado);

  printf("%s",desencriptado);

  fprintf(arch_saida,"%s",desencriptado);

  fclose(arch);

  return(EXIT_SUCCESS);
}
