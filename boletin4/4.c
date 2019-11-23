/*ENUNCIADO

Escribir unha función que reciba dúas cadeas de caracteres e devolva outra cadea de caracteres que conteña unicamente os caracteres comúns; de non habelos debe devolver un punteiro a NULL. O prototipo da función debe ser:

    char * CarCompartidos(char *cad1, char *cad2);

Lembrade que a cadea devolta debe levar o carácter de fin de cadea.*/

/*Autor: Aldán Creo Mariño
Data: 10 de novembro de 2019
Versión: 1
Este programa elabora unha cadea de caracteres que contén só os comúns a outras dúas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EXIT_SUCCESS 0

char *Ordear(char *cadea) //Esta funcion ordea os caracteres segundo o seu valor ASCII e despois elimina os repetidos
{
    char caracter_swap;
    char *cadea_ordeada = (char *)malloc(sizeof(*cadea) * (strlen(cadea) + 1)); //Reservamos o tamaño de memoria necesario para a cadea
    int correcto, i;

    strcpy(cadea_ordeada, cadea);

    do
    {
        correcto = 1;
        for (i = 1; cadea_ordeada[i] != '\0'; i++) //Comprobamos todos os pares de caracteres adxacentes da cadea
        {
            if (cadea_ordeada[i] < cadea_ordeada[i - 1]) //Se os dous caracteres estan en orde incorrecta, invertimolos
            {
                caracter_swap = cadea_ordeada[i - 1];
                cadea_ordeada[i - 1] = cadea_ordeada[i];
                cadea_ordeada[i] = caracter_swap;
                correcto = 0;
            }
        }
    } while (!correcto); //Repetimos o bucle mentres a orde non sexa a correcta

    int shift = 0; //Imos usar esta variable para determinar cantos caracteres temos que eliminar, e dicir, a cadea final tera unha lonxitude da cadea orixinal menos esta variable

    for (i = 1; cadea_ordeada[i] != '\0'; i++)
    {

        if (cadea_ordeada[i] == cadea_ordeada[i - 1]) //Par a par, comprobamos se hai caracteres iguais, xa que estan todos ordenados de antes
        {
            shift++; //Se son iguais, disminuimos a lonxitude da cadea
        }
        else
        {
            cadea_ordeada[i - shift] = cadea_ordeada[i]; //Se non son iguais, metemos o caracter na cadea final
        }
    }

<<<<<<< Updated upstream
    cadea_ordeada[i - shift] = '\0';
    cadea_ordeada = realloc(cadea_ordeada,sizeof(*cadea_ordeada) * (strlen(cadea_ordeada) + 1));
=======
    cadea_ordeada[i - shift] = '\0'; //Pechamos a cadea
>>>>>>> Stashed changes

    return (cadea_ordeada); //Devolvemos a cadea resultado
}

char *CarCompartidos(char *cad1, char *cad2)
{
    char *cad1_ord = Ordear(cad1); //Empezamos ordenando as cadeas e eliminando os caracteres duplicados
    char *cad2_ord = Ordear(cad2);

    char *cad_res = (char *)malloc(0); //Asignamoslle un espazo de 0 bytes a cadea de resultado
    char *cad_busqueda, *caracter_act;
    int i, long_cad_res = 0;
    for (caracter_act = cad1_ord; *caracter_act != '\0'; caracter_act++)
    {
        //printf("Tomando o caracter: %c\n", *caracter_act);

        int mitad_cadea = (ceil(((double)strlen(cad2_ord)) / ((double)2)));

        cad_busqueda = (char *)malloc(sizeof(*cad2_ord) * strlen(cad2_ord)); //creamos unha nova cadea de tamaño a metade da cadea 2

        strcpy(cad_busqueda, cad2_ord);
        //printf("\tCadea de busqueda: %s\n", cad_busqueda);

        while (strlen(cad_busqueda) > 1)
        {
            mitad_cadea = (ceil(((double)strlen(cad_busqueda)) / ((double)2)));

            if (*caracter_act >= cad_busqueda[mitad_cadea])
            {
                for (i = 0; i < mitad_cadea + 1; i++)
                {
                    cad_busqueda[i] = cad_busqueda[mitad_cadea + i];
                }
            }
            cad_busqueda = realloc(cad_busqueda, sizeof(*cad2_ord) * (mitad_cadea + 1));

            cad_busqueda[mitad_cadea] = '\0';
            //printf("\tCadea de busqueda: %s\n", cad_busqueda);
        }

        if (*cad_busqueda == *caracter_act)
        {
            long_cad_res++;
            cad_res = realloc(cad_res, sizeof(*cad_res) * long_cad_res);
            cad_res[long_cad_res - 1] = *cad_busqueda;
        }
    }

    long_cad_res++;
    cad_res = realloc(cad_res, sizeof(*cad_res) * long_cad_res);
    cad_res[long_cad_res - 1] = '\0';

    return (cad_res);
}

int main()
{
    char *cadea1, *cadea2;
    int lonx_cadea1 = 0, lonx_cadea2 = 0;

    cadea1 = malloc(0);
    cadea2 = malloc(0);

    printf("\nIntroduza a sua primeira cadea: ");

    do
    {
        lonx_cadea1++;
        cadea1 = realloc(cadea1, sizeof(*cadea1) * lonx_cadea1);
        cadea1[lonx_cadea1 - 1] = getchar();
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

    printf("Iniciando busqueda...\n");
    printf("\n%s", CarCompartidos(cadea1, cadea2));
    printf("\nFin da busqueda.\n");

    return (EXIT_SUCCESS);
}