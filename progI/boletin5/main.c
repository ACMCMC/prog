/* Aldán Creo Mariño
 * Este programa permite traballar con enteiros maiores que os permitidos polo ordenador
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_bignum.h"

#define CONCIDION_ARGUMENTO ((opcion == 'S') || (opcion == 'R') || (opcion == 'P') || (opcion == 'M') || (opcion == 'F') || (opcion == 'D') || (opcion == 's') || (opcion == 'r') || (opcion == 'p') || (opcion == 'm') || (opcion == 'f') || (opcion == 'd'))

int main(int argc, char **argv)
{
    char opcion, i, cadea_size, *cadea = NULL;
    bignum resultado, *vector_bignum = (bignum *)malloc(sizeof(bignum) * 2);

    if (argc > 4)
    { //Non se poden especificar mais de 4 argumentos
        printf("Especificaronse demasiados argumentos.\n\nEmpregue:\n\t%s -help\n\n\tpara obter axuda.\n", argv[0]);
        exit(1);
    }

    if ((argc == 1) || (argv[1][0] != '-'))
    { //Se non se especificou un argumento, mostramos un menu ao usuario para que elixa unha opcion

        printf("Seleccione a operacion:\n\tS: Suma\n\tR: Resta\n\tP: Producto\n\tM: Modulo\n\tF: Factorial\n\tD: Dividir\n");

        do
        {
            printf("Opcion: ");
            opcion = getchar();
            //Ignoramos o resto de caracteres introducidos, incluído o '\n'. Sería máis compacto usar fflush(stdin), pero trátase dun comportamento indefinido [4].
            while ((getchar()) != '\n')
                ;
        } while (!CONCIDION_ARGUMENTO); //Seguimos neste bucle mentres non se introduza unha opción correcta
    }

    if ((argc > 1) && (strcmp(argv[1], "-help") == 0)) //Se o primeiro argumento especificado é "-help", mostramos a axuda
    {
        printf("Uso do programa.\n\nEscriba:\n\t%s [opcion] [numero 1] [numero 2]\n\n\tpara usar o programa.\n\nOpcions admitidas:\n\tS: Suma\n\tR: Resta\n\tP: Producto\n\tM: Modulo\n\tF: Factorial\n\tD: Dividir\n\nSe non se especifican os numeros, pediranse en tempo de execucion.\n\nEmpregue a opcion \"-help\" para amosar este menu de axuda.\n", argv[0]);
        exit(0); //Saímos con código de éxito
    }

    if ((argc > 1) && (argv[1][0] == '-'))
    { //Se se especificou unha opcion
        if ((strlen(argv[1]) == 2) && ((argv[1][1] == 'S') || (argv[1][1] == 'R') || (argv[1][1] == 'P') || (argv[1][1] == 'M') || (argv[1][1] == 'F') || (argv[1][1] == 'D') || (argv[1][1] == 's') || (argv[1][1] == 'r') || (argv[1][1] == 'p') || (argv[1][1] == 'm') || (argv[1][1] == 'f') || (argv[1][1] == 'd')))
        {                        //... e se a nosa opcion e correcta...
            opcion = argv[1][1]; //Gardamola como a opcion elixida
        }
        else
        { //Se non e correcta, saimos do programa mostrando erro
            printf("Opcion non admitida.\n\nEmpregue:\n\t%s -help\n\n\tpara obter axuda.\n", argv[0]);
            exit(1);
        }
    }

    if (argc == 1)
    {
        i = 0; //Se non se especificaron argumentos, enton temos que pedir os dous nums
    }
    else if ((argc > 1) && (argv[1][0] == '-'))
    {
        i = argc - 2; //Fara falta pedir esa cantidade de nums
    }
    else
    {
        i = argc - 1;
    }

    if (opcion == 'D' || opcion == 'd')
    { //Se pedimos a multiplicación módulo n, imos pedir antes que nada o módulo
        vector_bignum = (bignum *)realloc(vector_bignum, sizeof(bignum) * 3);
        printf("Introduza o valor do modulo n: ");

        cadea_size = 0;
        cadea = NULL;
        do
        {
            cadea_size++;
            cadea = (char *)realloc(cadea, sizeof(*cadea) * cadea_size);
            cadea[cadea_size - 1] = getchar();
        } while (cadea[cadea_size - 1] != '\n');

        cadea[cadea_size - 1] = '\0';

        vector_bignum[2] = str2bignum(cadea);
    }

    if (i == 1)
    {
        vector_bignum[0] = str2bignum(argv[argc - 1]);
    }
    else if (i == 2)
    {
        vector_bignum[0] = str2bignum(argv[argc - 2]);
        vector_bignum[1] = str2bignum(argv[argc - 1]);
    }

    while (i < 1 || (i < 2 && !(opcion == 'F' || opcion == 'f')))
    {
        printf("Introduza un numero: ");

        cadea_size = 0;
        free(cadea);
        cadea = NULL;
        do
        {
            cadea_size++;
            cadea = (char *)realloc(cadea, sizeof(*cadea) * cadea_size);
            cadea[cadea_size - 1] = getchar();
        } while (cadea[cadea_size - 1] != '\n');

        cadea[cadea_size - 1] = '\0';

        vector_bignum[i] = str2bignum(cadea);

        i++;
    }

    switch (opcion)
    {
    case 'S':
    case 's':
        resultado = add(vector_bignum[0], vector_bignum[1]);
        break;

    case 'R':
    case 'r':
        resultado = resta(vector_bignum[0], vector_bignum[1]);
        break;
    case 'P':
    case 'p':
        resultado = mult(vector_bignum[0], vector_bignum[1]);
        break;
    case 'M':
    case 'm':
        resultado = modulo(vector_bignum[0], vector_bignum[1]);
        break;
    case 'F':
    case 'f':
        resultado = fact(vector_bignum[0]);
        break;
    case 'D':
    case 'd':
        resultado = multmod(vector_bignum[0], vector_bignum[1], vector_bignum[2]);

    default: //Este caso nunca se vai dar, porque xa nos aseguramos previamente de que a opción elixida é correcta
        exit(1);
        break;
    }

    if (errobignum == ERRO_FALSE)
        printf("\nO resultado e: %s, lonxitude %u\n", bignum2str(resultado), resultado.tam);
    else
        printf("Produciuse un erro. Codigo de erro %p.\n", errobignum);

    return (EXIT_SUCCESS);
}