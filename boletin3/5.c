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

float media(int *nums, int cantidad_nums)
{
  float media = 0;

  for (int i = 0; i < cantidad_nums; i++)
  {
    media += nums[i];
  }

  media = (media / cantidad_nums);

  return media;
}

int main()
{
  FILE *arch;
  int num[100], i;
  if ((arch = fopen("data.txt", "r")) == NULL)
  {
    printf("Erro abrindo o arquivo");
    exit(1);
  }
  for (i = 0; feof(arch) == 0; i++)
  {
    fscanf(arch, "%d", &num[i]);
    printf("Numero %d: %d\n", i, num[i]);
  }

  printf("A media dos valores e %f", media(num, i));

  return (EXIT_SUCCESS);
}
