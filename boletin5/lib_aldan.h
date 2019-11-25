#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef struct
{
    char signo;
    unsigned int tam;
    unsigned char *val;
} bignum;

void invertir_signo(bignum *n)
{
    if (n->signo == 0)
    {
        n->signo = -1;
    }
    else
    {
        n->signo = 0;
    }
}

int comparar_magnitud(bignum a, bignum b) //Devuelve 1 si el valor absoluto de a es mayor que el de b, -1 si es menor, y 0 si son iguales
{
    if (a.tam > b.tam)
    {
        return 1;
    }
    else if (b.tam > a.tam)
    {
        return -1;
    }
    else if (a.val > b.val)
    {
        return 1;
    }
    else if (b.val > a.val)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparar(bignum a, bignum b)
{
    if (a.signo != b.signo)
    {
        if (a.signo == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (a.tam > b.tam)
    {
        return 1;
    }
    else if (b.tam > a.tam)
    {
        return -1;
    }
    else if (a.val > b.val)
    {
        return 1;
    }
    else if (b.val > a.val)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bignum str2bignum(char *str)
{
    bignum num;
    int i, n = 0, conv = 0;
    if (strlen(str) < 1)
    {
        exit(EXIT_FAILURE);
    }

    if (*str == '-')
    {
        num.signo = -1;
        str++; //diminuímos a lonxitude da cadea en unha unidade
    } else if (*str == '+') {
        num.signo = 0;
        str++;
    }
    else
    {
        num.signo = 0;
    }

    num.val = NULL; //en principio, non temos valores para o número

    i = strlen(str); //imos empezar a ler a cadea dende o final para pasala a base 256

    while (i >= 0)
    {
        conv = conv + pow(10,n) * (str[i] - '0');
        if (conv > UCHAR_MAX){
            num.tam++;
            num.val = (unsigned char *)realloc(num.val, sizeof(unsigned char)*num.tam);
            num.val[num.tam-1] = conv % UCHAR_MAX; //Gardamos o resto
            conv = conv / UCHAR_MAX; //Como conv vai ser o noso seguinte byte, facemos a division enteira e gardamos o resultado como valor de partida
            n = 0;
        }
        i--;
        n++;
    }
    
    return num;
}

bignum add(bignum a, bignum b)
{
    bignum res;
    unsigned short res_temp;

    int i, carry = 0;

    if (comparar_magnitud(a, b) < 0)
    {
        res.tam = b.tam;
    }
    else
    {
        res.tam = a.tam;
    }

    res.val = (unsigned char *)malloc(sizeof(unsigned char) * res.tam);

    for (i = 0; (i < a.tam) && (i < b.tam); i++)
    {

        res_temp = ((unsigned short)a.val[i]) + ((unsigned short)b.val[i]) + carry;
        if (res_temp > USHRT_MAX)
        {
            res.val[i] = (unsigned char)(res_temp - USHRT_MAX);
            carry = 1;
        }
        else
        {
            carry = 0;
            res.val[i] = (unsigned char)res_temp;
        }
    }

    return res;
}

/*bignum sub(bignum a, bignum b)
{
}

bignum mult(bignum a, bignum b)
{
}

bignum remainder(bignum a, bignum b)
{
}

bignum fact(bignum n)
{
}

bignum div(bignum a, bignum b, bignum n)
{
}*/