/* Aldán Creo Mariño*/
#ifndef LIB_BIGNUM_H
#define LIB_BIGNUM_H
typedef struct
{
    enum
    {
        positivo,
        negativo,
        erro
    } sign;
    unsigned int tam;
    unsigned char *val;
} bignum;

#define ERRO_FALSE 0x0
#define ERRO_CARACTERES_NON_ADMITIDOS 0x1
#define ERRO_FACTORIAL_NEGATIVO 0x2

extern unsigned int errobignum;


//{(∀x : 0 < x AND x < N-1 : '0' <= str[x] AND str[x] <= '9') AND (∃x : x == 0 : str[x] == '-' OR ('0' <= str[x] AND str[x] <= '9')) AND (∃x : x == N-1 : str[x] == '\0')}
bignum str2bignum(char *str);
//{((∃x : x == 0 : str[x] == '-' : bignum.tam == N-2) OR (∃x : x == 0 : str[x] != '-' : bignum.tam == N-1)) AND ((∃x : x == 0 : str[x] == '-' : bignum.sign == negativo) OR (∃x : x == 0 : str[x] != '-' : bignum.sign == positivo)) AND ((∀x : 0 <= x AND x < bignum.tam : str[x] - '0' == bignum.val[x]) OR ((∃x : x == 0 : str[x] == '-') AND (∀x : 0 < x AND x <= bignum.tam : str[x] - '0' == bignum.val[x-1])))}

char *bignum2str(bignum num);

//{(((a.sign == positivo) OR (a.sign == negativo)) AND (∀x : 0 <= x AND x < a.tam : 0 <= a.val[x] AND a.val[x] <= 9)) AND (((b.sign == positivo) OR (b.sign == negativo)) AND (∀x : 0 <= x AND x < b.tam : 0 <= b.val[x] AND b.val[x] <= 9))}
bignum add(bignum a, bignum b);
//{(a.sign == b.sign : bignum.sign == a.sign) AND (a.sign == b.sign : bignum.sign == resta(a,b).sign) AND (∀x : 0 <= x AND x < bignum.tam : 0 <= bignum.val[x] AND bignum.val[x] <= 9 AND bignum.val[x] = a.val[x] + b.val[x] + carry) AND (bignum.sign == positivo) OR (bignum.sign == negativo) AND (a.tam >= b.tam : bignum.tam <= a.tam + 1) AND (a.tam < b.tam : bignum.tam <= b.tam + 1)}

//{(((a.sign == positivo) OR (a.sign == negativo)) AND (∀x : 0 <= x AND x < a.tam : 0 <= a.val[x] AND a.val[x] <= 9)) AND (((b.sign == positivo) OR (b.sign == negativo)) AND (∀x : 0 <= x AND x < b.tam : 0 <= b.val[x] AND b.val[x] <= 9))}
bignum resta(bignum a, bignum b);
//Poscondicións: un bignum correspondente á resta das entradas (a)-(b) de tamaño menor ou igual ao maior se os signos son iguais
//e de tamaño maior ou igual se non o son; co signo adecuado (se a operación equivale a unha suma chamamarase automáticamente).

//{(((a.sign == positivo) OR (a.sign == negativo)) AND (∀x : 0 <= x AND x < a.tam : 0 <= a.val[x] AND a.val[x] <= 9)) AND (((b.sign == positivo) OR (b.sign == negativo)) AND (∀x : 0 <= x AND x < b.tam : 0 <= b.val[x] AND b.val[x] <= 9))}
bignum mult(bignum a, bignum b);
//Poscondicións: un bignum de tamaño maior ou igual ao correspondente ao producto das entradas co signo adecuado.

//{(((a.sign == positivo) OR (a.sign == negativo)) AND (∀x : 0 <= x AND x < a.tam : 0 <= a.val[x] AND a.val[x] <= 9)) AND (((n.sign == positivo) OR (n.sign == negativo)) AND (∀x : 0 <= x AND x < n.tam : 0 <= n.val[x] AND n.val[x] <= 9))}
bignum modulo(bignum a, bignum n);
//Poscondicións: un bignum de lonxitude igual ou menor a (a) que corresponde co resultado de a%n.

//{((n.sign == positivo) OR (n.sign == negativo)) AND (∀x : 0 <= x AND x < n.tam : 0 <= n.val[x] AND n.val[x] <= 9)}
bignum fact(bignum n);
//Poscondicións: o factorial do número, tendo en conta que 0!=1.

//{(((a.sign == positivo) OR (a.sign == negativo)) AND (∀x : 0 <= x AND x < a.tam : 0 <= a.val[x] AND a.val[x] <= 9)) AND (((b.sign == positivo) OR (b.sign == negativo)) AND (∀x : 0 <= x AND x < b.tam : 0 <= b.val[x] AND b.val[x] <= 9)) AND (((n.sign == positivo) OR (n.sign == negativo)) AND (∀x : 0 <= x AND x < n.tam : 0 <= n.val[x] AND n.val[x] <= 9))}
bignum multmod(bignum a, bignum b, bignum n);
//Un bignum de lonxitude igual ou menor a (a)*(b) que corresponde co resultado de (a*b)%n.

#endif