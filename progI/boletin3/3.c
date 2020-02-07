/*Autor: Aldán Creo Mariño
Data: 30 de setembro de 2019
Versión: 1
Este programa cambia maiúsculas por minúsculas nun vector de chars*/

#include <stdio.h>

int cambiar_letras(char* letras) {
    int num_cambios = 0;

    for (int i = 0; letras[i] != '\0'; i++) {
        if ((letras[i] >= 'A') && (letras[i] <= 'Z')) {
            letras[i] = letras[i] + ('a' - 'A');
            num_cambios++;
        }
    }
    return (num_cambios);
}

int main(int argc, char** argv) {
    char vector[100];

    printf("Escriba unha secuencia de caracteres:\n");
    scanf("%s", vector);

    int num_cambios = cambiar_letras(vector);

    printf("%s, cambiados %d caracteres", vector, num_cambios);

    return (0);
}
