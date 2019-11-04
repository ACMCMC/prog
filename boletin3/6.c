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
#include <errno.h>

#include "lib_aldan.h"

void encriptar(char *string, char *encriptado)
{

  encriptado[0] = string[0];

  for (int i = 1; i < strlen(string); i++)
  {
    encriptado[i] = (string[i] + string[i - 1]) % 128;
  }
  encriptado[strlen(string)] = '\0';
}

int main()
{

  char string[100], encriptado[100];
  FILE *arch_saida, *arch_entrada;

  printf("Introduza o nome do arquivo de texto plano: ");
  abrir_arquivo(&arch_entrada, "r");  

  printf("Introduza o nome do arquivo de saida: ");
  abrir_arquivo(&arch_saida, "w");

int i = 0;

  while (feof(arch_entrada) == 0)
  {
    fscanf(arch_entrada,"%c",string[i]);
    i++;
  }
  string[i+1] = '\0';
  
  //fscanf(arch_entrada, "%s", string);
  
  printf("%s, %d caracteres\n", string, strlen(string));

  encriptar(string, encriptado);

  printf("%s", encriptado);

  fprintf(arch_saida, "%s", encriptado);

  fclose(arch_saida);
  fclose(arch_entrada);

  return (EXIT_SUCCESS);
}