/*ENUNCIADO

Escribide un programa para a realización de operacións de suma e multiplicación de vectores, coas seguintes condicións:

    ◦ Os datos dos vectores lense dun arquivo onde aparecerán en primeiro lugar o tamaño do primeiro vector, a continuación os seus datos, despois o tamaño do segundo vector e a continuación os seus datos. Ao programa hai que pasarlle o nome do arquivo na liña de comandos.

    ◦ O programa debe ser modular, sen variables globais e sen lectura nin escritura de datos fóra da función main(). O programa constará dunha función para a suma, outra para a multiplicación (escalar) sumando os produtos elemento e elemento, e outra para a multiplicación (tensorial) que supón unha operación de tipo matricial na que o primeiro vector se considera vector columna e o segundo se toma coma un vector fila.

    ◦ Os vectores non terán tamaño limitado e reservarase memoria para eles de xeito dinámico, unha vez lidos os datos do seu tamaño. Cando teñan tamaños diferentes rexeitaranse as operacións.*/

/*Autor: Aldán Creo Mariño
Data: 12 de novembro de 2019
Versión: 1
Este programa elabora unha cadea de caracteres que contén só os comúns a outras dúas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define EXIT_SUCCESS 0

int *suma(int tam_vec, int *v1, int *v2)
{
    int *suma = (int *)malloc(sizeof(*v1) * tam_vec);
    for (int i = 0; i < tam_vec; i++)
    {
        suma[i] = v1[i] + v2[i];
    }
    return (suma);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Precisase o nome do arquivo a abrir como un parametro do programa. Para obter axuda, escriba ? ou \"help\"\n");
        exit(1);
    }

    if((argv[1][0] == '?') || (strcmp(argv[1],"help") == 0)) {
        printf("Para utilizar o programa, introduza o nome do arquivo binario que conten os datos dos vectores. Este arquivo debese atopar na carpeta de execucion do programa, e ter permisos de lectura. O arquivo debera ter extension \".dat\"\n");        
        exit(EXIT_SUCCESS);
    }

    printf("Abrindo: %s\n", argv[1]);
    FILE *arq = fopen(argv[1], "rb");
    if (arq == NULL)
    {
        printf("Non se puido abrir o arquivo (%p %s)\n", errno, strerror(errno));
        exit(1);
    }

    char *cadea1, *cadea2;
    int lonx_cadea1 = 0, lonx_cadea2 = 0;

    cadea1 = malloc(0);
    cadea2 = malloc(0);

    printf("\nIntroduza a sua primeira cadea: ");

    do
    {
        lonx_cadea1++;
        cadea1 = realloc(cadea1, sizeof(*cadea1) * lonx_cadea1);
        scanf("%d", cadea1[lonx_cadea1 - 1]);
    } while (cadea1[lonx_cadea1 - 1] != '\n');

    cadea1[lonx_cadea1 - 1] = '\0';

    printf("\nLido: %s\n", cadea1);

    printf("\nIntroduza a sua segunda cadea: ");

    do
    {
        lonx_cadea2++;
        cadea2 = realloc(cadea2, sizeof(*cadea2) * lonx_cadea2);
        cadea2[lonx_cadea2 - 1] = getchar();
    } while (cadea2[lonx_cadea2 - 1] != '\n');

    cadea2[lonx_cadea2 - 1] = '\0';

    printf("\nLido: %s\n", cadea2);

    return (EXIT_SUCCESS);
}