/*ENUNCIADO

Escribide un programa para a realización de operacións de suma e multiplicación de vectores, coas seguintes condicións:

    ◦ Os datos dos vectores lense dun arquivo onde aparecerán en primeiro lugar o tamaño do primeiro vector, a continuación os seus datos, despois o tamaño do segundo vector e a continuación os seus datos. Ao programa hai que pasarlle o nome do arquivo na liña de comandos.

    ◦ O programa debe ser modular, sen variables globais e sen lectura nin escritura de datos fóra da función main(). O programa constará dunha función para a suma, outra para a multiplicación (escalar) sumando os produtos elemento e elemento, e outra para a multiplicación (tensorial) que supón unha operación de tipo matricial na que o primeiro vector se considera vector columna e o segundo se toma coma un vector fila.

    ◦ Os vectores non terán tamaño limitado e reservarase memoria para eles de xeito dinámico, unha vez lidos os datos do seu tamaño. Cando teñan tamaños diferentes rexeitaranse as operacións.*/

/*Autor: Aldán Creo Mariño
Data: 12 de novembro de 2019
Versión: 1
Este programa realiza operacións con vectores*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#define EXIT_SUCCESS 0

char *corrixirNome(char *nome_arq_orixinal)
{ //Esta funcion toma unha cadea de caracteres e comproba se acaba en ".dat"; se non, añadelle a extension e devolve a cadea corrixida

    char *nome_arq = (char *)malloc(sizeof(nome_arq_orixinal[0]) * (strlen(nome_arq_orixinal) + 1));

    strcpy(nome_arq, nome_arq_orixinal);

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
            nome_arq = realloc(nome_arq, sizeof(nome_arq_orixinal[0]) * (strlen(nome_arq_orixinal) + 5));
            strcat(nome_arq, ".dat"); //Engadimoslle ".dat"
        }
    }
    else
    {
        nome_arq = realloc(nome_arq, sizeof(nome_arq_orixinal[0]) * (strlen(nome_arq_orixinal) + 5));
        strcat(nome_arq, ".dat"); //Se a cadea non chega a media mais de 4 caracteres, non termina en ".dat" e hai que añadirllo
    }

    return nome_arq; //Devolvemos a cadea corrixida
}

int multip_escalar(int tam_vec, int *v1, int *v2)
{
    int multip = 0;

    for (int i = 0; i < tam_vec; i++)
    {
        multip = multip + (v1[i] * v2[i]);
    }

    return multip;
}

int **multip_tensorial(int tam_vec, int *v1, int *v2)
{
    int **multip = (int **)malloc(sizeof(*v1) * tam_vec);
    for (int i = 0; i < tam_vec; i++)
    {
        multip[i] = (int *)malloc(sizeof(*v2) * tam_vec);
        for (int j = 0; j < tam_vec; j++)
        {
            multip[i][j] = v1[i] * v2[j];
        }
    }

    return multip;
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

    int *vector1, *vector2, *vector_suma, **vector_mult_tensorial;
    int lonx_cadea1 = 0, lonx_cadea2 = 0;

    vector1 = malloc(0);
    vector2 = malloc(0);

    if (argc < 2) //Non se especificou un nome de ficheiro como argumento
    {
        printf("Precisase o nome do arquivo a abrir como un parametro do programa.\n\nPara obter axuda, use \"-help\".\n");
        exit(1);
    }

    if (/*(argv[1][0] == '\?') ||*/ (strcmp(argv[1], "-help") == 0)) //O usuario introduce -help como argumento
    {
        printf("Sintaxe:\n\t%s [-create_file] nome_arquivo [-1,-2,-3]\n\nPara utilizar o programa, introduza o nome do arquivo binario que conten os datos dos vectores. Este arquivo debese atopar na carpeta de execucion do programa, e ter permisos de lectura. O arquivo debera ter extension \".dat\".\n\nA continuacion do nome do arquivo, pode indicar o modo de operacion do programa, en caso de omitilo mostrarase un menu para seleccionar a opcion desexada en tempo de execucion.\n\nPode inicializar un arquivo cos datos de novos vectores co parametro \"-create_file\" (nome do arquivo).\n\n\t-1 realiza a suma dos vectores.\n\t-2 realiza a multiplicacion escalar.\n\t-3 realiza a multiplicacion tensorial.\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(argv[1], "-create_file") == 0)
    {
        if ((argc > 2) && (argv[2][0] != '-'))
        { //Se se introduciu "-create_file" e o segundo argumento non empeza con -

            char *nome_corrixido = corrixirNome(argv[2]); //Miramos se o nome do arquivo acaba en ".dat"

            //printf("Creando: %s\n", nome_corrixido);

            FILE *arq = fopen(nome_corrixido, "wb");
            if (arq == NULL)
            {
                printf("\nNon se puido crear o arquivo (%p - %s)\n", errno, strerror(errno));
                exit(1);
            }

            char caracter_actual;
            int num_actual, i, negativo;

            printf("\n\nCreando o vector 1...\n");

            do
            {
                lonx_cadea1++;
                printf("\tIntroduza o dato %d: ", lonx_cadea1);
                num_actual = 0;
                i = 0;
                negativo = 0;
                caracter_actual = '0';
                do
                {
                    if (caracter_actual == '-')
                    {
                        negativo = 1;
                    }
                    else
                    {
                        num_actual = num_actual * 10 + (caracter_actual - '0');
                    }
                    caracter_actual = getchar();
                    //printf("\n\tCaracter: %c, suma: %d", caracter_actual, num_actual);
                    i++;
                } while (((caracter_actual > '0') && (caracter_actual < '9')) || ((caracter_actual == '-') && (i == 1)));

                if (negativo)
                {
                    num_actual = num_actual * (-1);
                };

                vector1 = realloc(vector1, sizeof(*vector1) * lonx_cadea1);
                vector1[lonx_cadea1 - 1] = num_actual;

            } while ((caracter_actual != '\n') || (i > 1));

            lonx_cadea1--;
            vector1 = realloc(vector1, sizeof(*vector1) * lonx_cadea1);

            printf("Crearase o vector: (");
            for (i = 0; i < (lonx_cadea1 - 1); i++)
            {
                printf(" %d ,", vector1[i]);
            }
            printf(" %d )", vector1[lonx_cadea1 - 1]);

            printf("\n\nCreando o vector 2...\n");

            do
            {
                lonx_cadea2++;
                printf("\tIntroduza o dato %d: ", lonx_cadea2);
                num_actual = 0;
                i = 0;
                negativo = 0;
                caracter_actual = '0';
                do
                {
                    if (caracter_actual == '-')
                    {
                        negativo = 1;
                    }
                    else
                    {
                        num_actual = num_actual * 10 + (caracter_actual - '0');
                    }
                    caracter_actual = getchar();
                    //printf("\n\tCaracter: %c, suma: %d", caracter_actual, num_actual);
                    i++;
                } while (((caracter_actual > '0') && (caracter_actual < '9')) || ((caracter_actual == '-') && (i == 1)));

                if (negativo)
                {
                    num_actual = num_actual * (-1);
                };

                vector2 = realloc(vector2, sizeof(*vector2) * lonx_cadea2);
                vector2[lonx_cadea2 - 1] = num_actual;

            } while ((caracter_actual != '\n') || (i > 1));

            lonx_cadea2--;
            vector2 = realloc(vector2, sizeof(*vector2) * lonx_cadea2);

            printf("\n\nCrearase o vector: (");
            for (i = 0; i < (lonx_cadea2 - 1); i++)
            {
                printf(" %d ,", vector2[i]);
            }
            printf(" %d )\n", vector2[lonx_cadea2 - 1]);

            fwrite(&lonx_cadea1, sizeof(lonx_cadea1), 1, arq);
            fwrite(vector1, sizeof(*vector1), lonx_cadea1, arq);
            fwrite(&lonx_cadea2, sizeof(lonx_cadea2), 1, arq);
            fwrite(vector2, sizeof(*vector2), lonx_cadea2, arq);

            if (fclose(arq))
            {
                printf("Erro: %s (%p)\n", strerror(errno), errno);
                exit(1);
            }
            else
            {
                printf("Datos gardados con exito en %s.\n", nome_corrixido);
                exit(EXIT_SUCCESS);
            }
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

    fread(&lonx_cadea1, sizeof(lonx_cadea1), 1, arq);
    //printf("Lonxitude do primeiro vector: %d\n",lonx_cadea1);
    fread(vector1, sizeof(*vector1), lonx_cadea1, arq);
    fread(&lonx_cadea2, sizeof(lonx_cadea2), 1, arq);
    fread(vector2, sizeof(*vector2), lonx_cadea2, arq);

    int i;

    printf("Lidos os vectores: (");
    for (i = 0; i < (lonx_cadea1 - 1); i++)
    {
        printf(" %d ,", vector1[i]);
    }
    printf(" %d ) , (", vector1[lonx_cadea1 - 1]);

    for (i = 0; i < (lonx_cadea2 - 1); i++)
    {
        printf(" %d ,", vector2[i]);
    }
    printf(" %d )\n", vector2[lonx_cadea2 - 1]);

    if (lonx_cadea1 != lonx_cadea2)
    {
        printf("Os vectores teñen distintas lonxitudes, polo que non se pode operar con eles.\n");
        exit(EXIT_SUCCESS);
    }

    vector_suma = (int *)malloc(sizeof(*vector1) * lonx_cadea1);

    int opcion;

    if ((argc == 2) ||
        ((argc > 2) &&
         ((strlen(argv[1]) < 2) ||
          ((strlen(argv[1]) > 1) && (argv[1][0] == '-') && (argv[1][1] > '3') || (argv[1][1] < '1')))))
    {
        //O usuario non pasou unha opcion como parametro. Mostramos ao usuario un menu para elixir a sua opcion co programa
        printf("\nQue desexa facer?\n\n\t1. Realizar a suma dos dous vectores.\n\t2. Realizar a multiplicacion escalar dos vectores.\n\t3. Realizar a multiplicacion tensorial dos vectores.\n");

        scanf("%d", &opcion);
    }
    else
    {
        opcion = (argv[2][1] - '0');
    }
    switch (opcion)
    {
    case 1:
        vector_suma = suma(lonx_cadea1, vector1, vector2);
        printf("\nO resultado da suma e: (");
        for (i = 0; i < (lonx_cadea1 - 1); i++)
        {
            printf(" %d ,", vector_suma[i]);
        }
        printf(" %d )\n", vector_suma[lonx_cadea1 - 1]);
        break;
    case 2:
        printf("\n\nO resultado da multiplicacion escalar e %d.\n", multip_escalar(lonx_cadea1, vector1, vector2));
        break;
    case 3:
        vector_mult_tensorial = multip_tensorial(lonx_cadea1, vector1, vector2);
        printf("\n\nO resultado e:\n");
        for (int i = 0; i < lonx_cadea1; i++)
        {
            printf("(");
            for (int j = 0; j < lonx_cadea2; j++)
            {
                printf(" %d ", vector_mult_tensorial[i][j]);
            }
            printf(")\n");
        }

        break;
    default:
        printf("Opcion non admitida.\n");
        break;
    }

    fclose(arq);

    return (EXIT_SUCCESS);
}