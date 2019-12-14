/* 
 * Guillermo Blanco Filgueira
 * 25 de noviembre de 2019
 */
//!!!ALGÚNS NOMES DAS FUNCIÓNS FORON MODIFICADOS POR INTERFERIR CON NOMES DAS LIBREÍAS STANDARD
#ifndef GRANDESNUMEROS_H
#define GRANDESNUMEROS_H
typedef struct
{
    char sign; //Sign = 0 para positivos, 1 para negativos 
    unsigned int tam;
    char *val;
} bignum;

extern int errobignum;

#define ERRO_CARACTERES_NON_ADMITIDOS 1
#define ERRO_FACTORIAL_NEGATIVO 2

//Precondicións: pasarlle unha cadena de caracteres do 0-9 de calquera lonxitude non nula, con signo e sen parte decimal, cun \n ao final.
bignum str2bignum(char *str);
//Poscondicións: un bignum co signo adecuado (se non existe interpretaráse como positivo) cuxo tamaño é menor ou igual ao da cadea
//e cuxo vector de datos enteiros son os valores correspondentes aos díxitos representados na cadea, ELIMINANDO CEROS Á ESQUERDA.

//TODO: Engadir descricion da funcion
char * bignum2str(bignum num);

//Precondicións: dous bignums de calquer signo e tamaño.
bignum add(bignum a, bignum b);
//Poscondicións: un bignum correspondente á suma das entradas de tamaño igual ou maior ao maior deles
//e co signo adecuado (se a operación equivale a unha resta chamamarase automáticamente).

//Precondicións: dous bignums de calquer signo e tamaño, sen ceros á esquerda no valor.
bignum resta(bignum a, bignum b);
//Poscondicións: un bignum correspondente á resta das entradas (a)-(b) de tamaño menor ou igual ao maior se os signos son iguais
//e de tamaño maior ou igual se non o son; co signo adecuado (se a operación equivale a unha suma chamamarase automáticamente).

//Precondicións: dous bignums de calquer signo e tamaño.
bignum mult(bignum a, bignum b);
//Poscondicións: un bignum de tamaño maior ou igual ao correspondente ao producto das entradas co signo adecuado.

//Precondicións: dous bignums de calquer tamaño e signo sen ceros á esquerda no valor; o bignum (n) NON pode ser NULO.
bignum modulo(bignum a, bignum n);
//Poscondicións: un bignum de lonxitude igual ou menor a (a) que corresponde co resultado de a%n.

//Precondicións: un bignum de signo positivo, sen ceros á esquerda no valor, igual ou maior a 0; do contrario abortarase o programa.
bignum fact(bignum n);
//Poscondicións: o factorial do número, tendo en conta que 0!=1.

//Precondicións: dous bignums de calquer tamaño e signo; e un bignum (n) que NON sexa NULO e sen ceros á esquerda no valor.
bignum multmod(bignum a, bignum b, bignum n);
//Un bignum de lonxitude igual ou menor a (a)*(b) que corresponde co resultado de (a*b)%n.

#endif