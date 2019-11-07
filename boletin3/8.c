/*ENUNCIADO

Dados dous vectores U e V, defínese a distancia de Hamming, d(U,V), coma o número de posicións nas que
difiren os vectores. Por exemplo, se U = 20001 e V = 10103,  d(U,V) = 3, xa que existen tres posicións
nas cales os vectores teñen diferente valor. Escribide unha función, denominada Hamming, que reciba como
parámetros dúas cadeas de caracteres e devolva un enteiro que indique a distancia Hamming entre elas. Se
as cadeas non teñen lonxitudes iguais a función devolverá -1. Empregar esa función dentro dun programa en
C que pida ao usuario unha chave de paso  (cadea de caracteres), e que a compare coas almacenadas nun arquivo
denominado chaves.dat xa existente  e que, despois de chamar á función Hamming, amose por pantalla unha
mensaxe indicando se a  cadea dada polo usuario coincide ou non con algunha das almacenadas no arquivo
chaves.dat. Considerar que as chaves de paso do arquivo están encriptadas segundo o método anterior e que
por tanto fai falta desencriptalas para facer a comparación.*/

/*Autor: Aldán Creo Mariño
Data: 4 de novembro de 2019
Versión: 1
Este programa traballa con datos encriptados*/

#include "lib_aldan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define N 30

int Hamming(char *vec1, char *vec2) //Para facer a función Hamming, necesitamos dous vectores de caracteres que comparar
{
  if (!(strlen(vec1) == strlen(vec2))) //Comparamos as lonxitudes dos vectores
  {
    //Os vectores non se poden comparar porque teñen distinta lonxitude, así que devolvemos -1
    return (-1);
  }

  int hamming = 0; //Se non hai ningún caracter distinto, a función valerá 0

  for (int i = 0; i < strlen(vec1); i++) //Aumentamos de cada vez a posición que escaneamos nunha unidade
  {
    if (vec1[i] != vec2[i]) //Se o carácter é distinto entre as dúas cadeas...
    {
      hamming++; //...entón Hamming vale un máis
    }
  }
  return hamming; //Devolvemos o número de posicións distintas
}

int main()
{
  FILE *arch;
  char linha[N], contrasena[N];

  printf("Introduza o nome do arquivo de contrasenas: ");
  arch = abrir_arquivo("r"); //Abrimos o arquivo de contraseñas coa función abrir_arquivo, en modo lectura

  printf("\nIntroduza a sua contrasena: ");
  getchar();        //Como o scanf anterior deixa un retorno de carro no búfer de lectura, quitamos o último caracter
  gets(contrasena); //Escaneamos a contraseña que introduza o usuario

  char cont_cifrada[N];

  encriptar(contrasena, cont_cifrada); //Encriptamos a contraseña introducida para poder comparala

  int coinciden = 0;

  while (feof(arch) == 0) //Imos lendo todas as liñas do arquivo de claves para ver se algunha coincide
  {
    ler_linha(arch, linha, N);
    if (Hamming(linha, cont_cifrada) == 0)
    {
      coinciden = 1; //Se coinciden, saímos do bucle e asignámoslle verdadeiro á variable de control (int coinciden)
      break;
    }
  }

  if (coinciden)
  {
    printf("\nAcceso garantido\n");
  }
  else
  {
    printf("\nAcceso denegado\n");
  }

  if (fclose(arch))
  { //Pechamos o arquivo antes de rematar
    return (EXIT_FAILURE); //Se houbo un fallo ó pechalo, devolvemos fallo
  }
  else
  {
    return (EXIT_SUCCESS); //Devolvemos 0 se se pechou correctamente
  }
}