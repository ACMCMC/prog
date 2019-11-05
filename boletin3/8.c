#include "lib_aldan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define N 30

int Hamming(char *vec1, char *vec2)
{
  if (!(strlen(vec1) == strlen(vec2)))
  {
    //printf("Os vectores non se poden comparar porque teñen distinta lonxitude");
    return (-1);
  }

  int hamming = 0;

  for (int i = 0; i < strlen(vec1); i++)
  {
    if (vec1[i] != vec2[i])
    {
      hamming++;
    }
  }
  return hamming;
}

int main()
{
  FILE *arch;
  char linha[N], contrasena[N];

  printf("Introduza o nome do arquivo de contrasenas: ");
  arch = abrir_arquivo("r");

  printf("\nIntroduza a sua contrasena: ");
  getchar();
  gets(contrasena);

char cont_cifrada[N];

  encriptar(contrasena, cont_cifrada);

  int coinciden = 0;

  while (feof(arch) == 0)
  {
    ler_linha(arch, linha, N);
    if (Hamming(linha, cont_cifrada) == 0)
    {
      coinciden = 1;
      break;
    }
  }

  if(coinciden) {
    printf("\nAcceso garantido\n");
  } else {
    printf("\nAcceso denegado\n");
  }

  fclose(arch);

  return (EXIT_SUCCESS);
}