//Autor: Creo Mariño, Aldán
//Función potencia baseada na ofrecida no Campus Virtual

#define EXIT_SUCCESS 1
#include <stdlib.h>
#include <stdio.h>

int potencia(int base, int exponente) {
    int resultado = 1;
    while (exponente > 0) {
        resultado *= base;
        exponente--;
    }
    return ((exponente < 0)? 1.0/((float) resultado) : resultado);
}

int main(int argc, char** argv) {
    int a[4];
    int b;
    int c[4];

    unsigned short i;

    printf("Catro valores para elevar: ");
    scanf("%d %d %d %d", a, a+1, a+2, a+3);

    printf("\nExponente: ");
    scanf("%d", &b);

    for (i = 0; i < 4; i++) {
        c[i] = potencia(a[i], b);
    }

    printf("\nResultados: {%d, %d, %d, %d}\n", *(c), *(c+1), *(c+2), *(c+3));

    return(EXIT_SUCCESS);
}