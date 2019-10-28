/*Autor: Aldán Creo Mariño
Data: 30 de setembro de 2019
Versión: 1
Este programa encontra o promedio de dous números*/

#define EXIT_SUCCESS 0

#include <stdio.h>

#include <stdlib.h>

float encontprom(int num1, int num2) {
  float promedio;
  promedio = (num1 + num2) / 2.0;
  return (promedio);
}

int main() {
  int a, b;
  float resultado;
  printf("Dame dous valores enteiros: ");
  scanf("%d %d", & a, & b);
  resultado = encontprom(a, b);
  printf("Promedio=%f\n", resultado);
  return (EXIT_SUCCESS);
}
