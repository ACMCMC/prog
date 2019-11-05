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

int main()
{

  char string[100], encriptado[100];
  FILE *arch_saida, *arch_entrada;

  printf("Introduza o nome do arquivo de texto plano: ");
  arch_entrada = abrir_arquivo("r");

  printf("Introduza o nome do arquivo de saida: ");
  arch_saida = abrir_arquivo("w");

  int i = 0;

  while (feof(arch_entrada) == 0)
  {
    fscanf(arch_entrada, "%c", &string[i]);
    i++;
  }
  string[i-1] = '\0';

  printf("Lido: %s, %d caracteres\n", string, strlen(string));

  encriptar(string, encriptado);

  printf("%s", encriptado);

  fprintf(arch_saida, "%s", encriptado);

  fclose(arch_saida);
  fclose(arch_entrada);

  return (EXIT_SUCCESS);
}