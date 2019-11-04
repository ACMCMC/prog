#include "lib_aldan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0

int Hamming(char *vec1, char *vec2) {
  if (!(strlen(vec1) == strlen(vec2))) {
    printf("Os vectores non se poden comparar porque teñen distinta lonxitude");
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

  printf("Introduza o nome do arquivo de contraseñas");
  arch = abrir_arquivo("r");

  return (EXIT_SUCCESS);
}