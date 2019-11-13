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
#include <math.h>
#include <errno.h>

#define EXIT_SUCCESS 0

char *corrixirNome(char *nome_arq)
{ //Esta funcion toma unha cadea de caracteres e comproba se acaba en ".dat"; se non, añadelle a extension e devolve a cadea corrixida

    if (strlen(nome_arq) > 4) //Se a cadea non mide mais de 4 caracteres, non pode ser algo seguido de ".dat"
    {
        char final[5]; //Se a cadea ten mais de 4 caracteres, creamos unha cadea temporal para almacenar os ultimos 4 caracteres da cadea e comparalos para ver se son ".dat"

        for (int i = 3; i >= 0; i--) //Insertamos os ultimos 4 caracteres da cadea orixinal na cadea temporal que se chama "final"
        {
            final[3 - i] = nome_arq[strlen(nome_arq) - i - 1];
        }
        final[4] = '\0'; //Rematamos o caracter final da cadea

        if (strcmp(final, ".dat") != 0) //Se a cadea non acaba en ".dat"...
        {
            strcat(nome_arq, ".dat"); //Engadimoslle ".dat"
        }
    }
    else
    {
        strcat(nome_arq, ".dat"); //Se a cadea non chega a media mais de 4 caracteres, non termina en ".dat" e hai que añadirllo
    }

    return nome_arq; //Devolvemos a cadea corrixida
}

int *suma(int tam_vec, int *v1, int *v2) //Sumamos os dous vectores
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
    if (argc < 2) //Non se especificou un nome de ficheiro como argumento
    {
        printf("Precisase o nome do arquivo a abrir como un parametro do programa.\n\nPara obter axuda, use \"-help\".\n");
        exit(1);
    }

    if (/*(argv[1][0] == '\?') ||*/ (strcmp(argv[1], "-help") == 0)) //O usuario introduce -help como argumento
    {
        printf("Para utilizar o programa, introduza o nome do arquivo binario que conten os datos dos vectores. Este arquivo debese atopar na carpeta de execucion do programa, e ter permisos de lectura. O arquivo debera ter extension \".dat\".\n\nPode inicializar un arquivo cos datos de novos vectores co parametro \"-create_file\" (nome do arquivo).\n");
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(argv[1], "-create_file") == 0)
    {
        if ((argc > 2) && (argv[2][0] != '-'))
        { //Se se introduciu "-create_file" e o segundo argumento non empeza con -

            char *nome_corrixido = corrixirNome(argv[2]); //Miramos se o nome do arquivo acaba en ".dat"

            printf("Creando: %s\n", nome_corrixido);
            FILE *arq = fopen(nome_corrixido, "wb");
            if (arq == NULL)
            {
                printf("\nNon se puido crear o arquivo (%p - %s)\n", errno, strerror(errno));
                exit(1);
            }

            int *cadea1, *cadea2;
            int lonx_cadea1 = 0, lonx_cadea2 = 0;

            cadea1 = malloc(0);
            cadea2 = malloc(0);

            char caracter_actual;
            int num_actual, i;

            printf("\nCreando o vector 1...");

            do
            {
                lonx_cadea1++;
                printf("\nIntroduza o dato %d: ", lonx_cadea1);
                num_actual = 0;
                i = 0;
                caracter_actual = '0';
                do
                {
                    num_actual = num_actual * 10 + (caracter_actual - '0');
                    caracter_actual = getchar();
                    //printf("\n\tCaracter: %c, suma: %d", caracter_actual, num_actual);
                    i++;
                } while ((caracter_actual > '0') && (caracter_actual < '9'));

                cadea1 = realloc(cadea1, sizeof(*cadea1) * lonx_cadea1);
                cadea1[lonx_cadea1 - 1] = num_actual;

            } while ((caracter_actual != '\n') || (i > 1));

            lonx_cadea1--;
            cadea1 = realloc(cadea1, sizeof(*cadea1) * lonx_cadea1);

            printf("Crearase o vector: (");
            for (i = 0; i < (lonx_cadea1 - 1); i++)
            {
                printf(" %d ,", cadea1[i]);
            }
            printf(" %d )\n", cadea1[lonx_cadea1 - 1]);

            printf("\nCreando o vector 2...");

            do
            {
                lonx_cadea2++;
                printf("\nIntroduza o dato %d: ", lonx_cadea2);
                num_actual = 0;
                i = 0;
                caracter_actual = '0';
                do
                {
                    num_actual = num_actual * 10 + (caracter_actual - '0');
                    caracter_actual = getchar();
                    //printf("\n\tCaracter: %c, suma: %d", caracter_actual, num_actual);
                    i++;
                } while ((caracter_actual > '0') && (caracter_actual < '9'));

                cadea2 = realloc(cadea2, sizeof(*cadea2) * lonx_cadea2);
                cadea2[lonx_cadea2 - 1] = num_actual;

            } while ((caracter_actual != '\n') || (i > 1));

            lonx_cadea2--;
            cadea2 = realloc(cadea2, sizeof(*cadea2) * lonx_cadea2);

            printf("Crearase o vector: (");
            for (i = 0; i < (lonx_cadea2 - 1); i++)
            {
                printf(" %d ,", cadea2[i]);
            }
            printf(" %d )\n", cadea2[lonx_cadea2 - 1]);



            fwrite(&lonx_cadea1, sizeof(lonx_cadea1), 1, arq);
            fwrite(cadea1, sizeof(*cadea1), lonx_cadea1, arq);
            fwrite(&lonx_cadea2, sizeof(lonx_cadea2), 1, arq);
            fwrite(cadea2, sizeof(*cadea2), lonx_cadea2, arq);

            fclose(arq);

            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Sintaxe non admitida.\n\n\tUso: -create_file (nome do arquivo) \n\nPara obter axuda, use \"-help\".\n");
            exit(1);
        }
    }
    else if (argv[1][0] == '-')
    {
        printf("Sintaxe non admitida.\n\nPara obter axuda, use \"-help\".\n");
        exit(1);
    }

    char *nome_corrixido = corrixirNome(argv[1]); //Miramos se o nome do arquivo acaba en ".dat"

    printf("Abrindo: %s\n", nome_corrixido);
    FILE *arq = fopen(nome_corrixido, "rb");
    if (arq == NULL)
    {
        printf("\nNon se puido abrir o arquivo (%p - %s)\n", errno, strerror(errno));
        exit(1);
    }

    fclose(arq);

    return (EXIT_SUCCESS);
}