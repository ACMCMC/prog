/*Autor: Aldán Creo Mariño
Data: 30 de setembro de 2019
Versión: 1

Este programa devolve un vector de caracteres (que introduce o usuario), pero ó revés*/

#define EXIT_SUCCESS 0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Esta función dalle a volta ó vector de chars*/

char* backwards(char palabra[], int lonxitude, char* saveto) {
int index;
for(int i = 0; i < (lonxitude + 1); i++) {
index = lonxitude-i-1;
saveto[i] = palabra[index];
}
saveto[lonxitude] = '\0';
return(saveto);
}

int main() {
char palabra[100]; /*declaramos variables*/
int num_caracteres;
/*preguntámoslle unha palabra ao usuario*/

printf("Escriba unha palabra:\n");
scanf("%s",palabra);

num_caracteres = strlen(palabra);
char back[num_caracteres];

/*Dámoslle a volta á palabra*/
backwards(palabra,num_caracteres,back);
printf("%s",back);
return(EXIT_SUCCESS);
}
