/* Autor : Guillermo Blanco Filgueira
 * Data : 18 de novembro de 2019
 * Este programa permite traballar con enteiros maiores que os permitidos polo ordenador
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesnumeros.h"

int main(int argc, char **argv)
{
char opcion;

    if ((argc == 1) || (argv[1][0] != '-')) { //Se non se especificou un argumento, mostramos un menu ao usuario para que elixa unha opcion

    printf("Seleccione a operación:\n\tS: Suma\n\tR: Resta\n\tP: Producto\n\tM: Módulo\n\tF: Factorial\n\tD: Dividir\n");

    do {
        printf("Opcion> ");
    scanf("%c",&opcion);
    getchar();
    } while (!((opcion == 'S') || (opcion =='R') || (opcion == 'P') || (opcion == 'M') || (opcion == 'F') || (opcion == 'D')));
    }

    if ((argc > 1) && (strcmp(argv[1],"-help") == 0)) {
        printf("Uso do programa.\n\nEscriba:\n\t%s [opcion] [numero 1] [numero 2]\n\n\tpara usar o programa.\n\nOpcions admitidas:\n\tS: Suma\n\tR: Resta\n\tP: Producto\n\tM: Módulo\n\tF: Factorial\n\tD: Dividir\n\nSe non se especifican os numeros, pediranse en tempo de execucion.\n\nEmpregue a opcion \"-help\" para amosar este menu de axuda.\n",argv[0]);
        exit(0);
    }

    

    char operacion, letra, *valor1, *valor2, *valor3, *out;
    int lonx, limpar = 1;
    bignum num1, num2, num3, result;
    scanf("%c", &operacion);
    //Preparamos os números
    if (operacion == 's' || operacion == 'S' || operacion == 'r' || operacion == 'R' || operacion == 'p' || operacion == 'P' || operacion == 'm' || operacion == 'M')
    {
        //PRIMEIRO NUMERO
        printf("Introduza a lonxitude máxima dos números: ");
        scanf("%d", &lonx);
        getchar();
        lonx = lonx + 2;
        valor1 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o primeiro número: ");
        fgets(valor1, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor1[i] == '\n')
            {
                valor1[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor1[0] != '-' && valor1[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor1[i] = valor1[i - 1];
            valor1[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
        //SEGUNDO NUMERO
        limpar = 1;
        valor2 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o segundo número: ");
        fgets(valor2, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor2[i] == '\n')
            {
                valor2[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor2[0] != '-' && valor2[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor2[i] = valor2[i - 1];
            valor2[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
        num1 = str2bignum(valor1);
        num2 = str2bignum(valor2);
        free(valor1);
        free(valor2);
    }
    else if (operacion == 'f' || operacion == 'F')
    {
        //PRIMEIRO NUMERO
        printf("Introduza a lonxitude do número: ");
        scanf("%d", &lonx);
        getchar();
        lonx = lonx + 2;
        valor1 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o primeiro número: ");
        fgets(valor1, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor1[i] == '\n')
            {
                valor1[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor1[0] != '-' && valor1[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor1[i] = valor1[i - 1];
            valor1[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
    }
    else
    {
        //PRIMEIRO NUMERO
        printf("Introduza a lonxitude máxima dos números: ");
        scanf("%d", &lonx);
        getchar();
        lonx = lonx + 2;
        valor1 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o primeiro número: ");
        fgets(valor1, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor1[i] == '\n')
            {
                valor1[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor1[0] != '-' && valor1[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor1[i] = valor1[i - 1];
            valor1[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
        //SEGUNDO NUMERO
        limpar = 1;
        valor2 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o segundo número: ");
        fgets(valor2, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor2[i] == '\n')
            {
                valor2[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor2[0] != '-' && valor2[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor2[i] = valor2[i - 1];
            valor2[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
        //Terceiro NUMERO
        limpar = 1;
        valor3 = (char *)malloc(sizeof(char) * (lonx));
        printf("Introduza o segundo número: ");
        fgets(valor3, lonx, stdin);
        for (int i = 0; i < lonx; i++)
        {
            if (valor3[i] == '\n')
            {
                valor3[i] = '\0'; //Se o número introducido foi menor desplazamos o final da cadea
                limpar = 0;       //Se este é o caso non fai falta limpar o stdin
            }
        }
        if (valor3[0] != '-' && valor3[0] != '+')
        { //Se o usuario non introduciu signo, o programa introduce un +
            for (int i = lonx - 2; i > 0; i--)
                valor3[i] = valor3[i - 1];
            valor3[0] = '+';
        }
        if (limpar == 1)
        {
            while (getchar() != '\n')
                ; //Limpamos o buffer se queda algún caracter
        }
        num1 = str2bignum(valor1);
        num2 = str2bignum(valor2);
        num3 = str2bignum(valor3);
        free(valor1);
        free(valor2);
        free(valor3);
    }
    switch (operacion)
    {
    case 'S':
    case 's':
        result = add(num1, num2);
        break;
    case 'R':
    case 'r':
        result = resta(num1, num2);
        break;
    case 'p':
    case 'P':
        result = mult(num1, num2);
        break;
    case 'M':
    case 'm':
        result = modulo(num1, num2);
        break;
    case 'F':
    case 'f':
        result = fact(num1);
        break;
    case 'D':
    case 'd':
        result = dividir(num1, num2, num3);
        break;
    default:
        printf("Non se recoñece ese comando");
        return (EXIT_FAILURE);
    }
    //Imprimir resultado
    printf("Resultado: ");
    if (result.sign == 1)
        printf("-");
    for (int i = result.tam - 1; i >= 0; i--)
        printf("%d", result.val[i]);
    return (EXIT_SUCCESS);
}
