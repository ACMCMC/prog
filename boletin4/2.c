/*ENUNCIADO

Os punteiros son variables que almacenan enderezos de memoria. Segundo o tipo de dato do punteiro, así se interpretará o valor accedido, tendo en conta tanto o número de bytes consecutivos que se usan na súa representación, coma o propio modo de representación. Por exemplo, definide unha variable de tipo unsigned int e asignádelle un valor, e despois accedede aos 4 bytes dese enteiro, un a un, empregando un punteiro a unsigned char, que apunte inicialmente ao primeiro byte do enteiro. Definide agora un vector de 4 caracteres de tipo unsigned char, asignádelle valores aos seus elementos, e accedede a eles con punteiros de tipo int* e char*. Probade con distintos valores. Con este exercicio evidenciamos que o tipo do punteiro co que accedamos a unha posición de memoria é determinante á hora de interpretar o dato alí gardado.*/

/*Autor: Aldán Creo Mariño
Data: 10 de novembro de 2019
Versión: 1
Este programa realiza operacións básicas con direccións de memoria*/

#include <stdio.h>

#define EXIT_SUCCESS 0

int main() {
    unsigned int num1 = 100;
     unsigned char *punt = &num1; //como un int ten 4 bytes, asígnaselle o seu byte menos significativo (porque en memoria os bytes gárdanse de menos a máis significativo)
     unsigned char punt2[3] = {'a','b','c','d'}; //en memoria, gardaranse en orde, como 4 bytes consecutivos
     unsigned int *punt3 = punt2; //como os ints teñen 4 bytes, e se leen de menos a máis significativos, será o resultado de sumar ('d' * 2^24 + 'c' * 2^16 + 'b' * 2^8 + 'a' * 2^0)
     printf("%d\n",num1); //isto imprime 100
     printf("%c\n",*punt); //isto imprime tamén 100, porque estamos tendo só en conta o primeiro byte, e 100 cabe nese primeiro byte
     printf("%s\n",punt2); //aquí imprime abcd, porque estamos lendo os bytes en orde coma se foran caracteres ASCII
     printf("%d\n",*punt3); //aquí devolve o resultado da suma anterior, 1684234849, que en binario é 01100100 ('d') 01100011 ('c') 01100010 ('b') 01100001 ('a')

    return(EXIT_SUCCESS);
}