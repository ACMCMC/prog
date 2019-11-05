#include "lib_aldan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define N 30

int Hamming(char *vec1, char *vec2) {
  if (!(strlen(vec1) == strlen(vec2))) {
    //printf("Os vectores non se poden comparar porque teñen distinta lonxitude");
    return(-1);
  }

  int hamming = 0;

  for (int i = 0; i < strlen(vec1); i++) {
    if (vec1[i] != vec2[i]) {
      hamming++;
    }
  }
  return hamming;
}

int main() {
  FILE *arch;
  char linha[N], contrasena[N];

  printf("Introduza o nome do arquivo de contrasenas: ");
  arch = abrir_arquivo("r");

  getchar();
  gets(contrasena);

  while(feof(arch) == 0) {
    ler_linha(arch,linha,N);
    if(Hamming(linha,contrasena) == 0) {
      printf("Acceso garantido\n");
      break;
    }
  }

  fclose(arch);

  return (EXIT_SUCCESS);
}