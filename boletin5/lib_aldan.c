#include "lib_aldan.h"

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
    int i = 0, n = 0, conv = 0;
    if (strlen(str) < 1)
    {
        exit(EXIT_FAILURE);
    }

    if (*str == '-')
    {
        num.signo = -1;
        i = 1;
    }
    else
    {
        num.signo = 0;
        i = 0;
    }

unsigned char *cociente = NULL, cociente_size = 0;

    while (i < strlen(str))
    {
        conv = conv*10 + (str[i]-'0');
        printf("Temos: %d",conv);
        if (conv >= UCHAR_MAX){
            cociente_size++;
            cociente = (unsigned char *)realloc(cociente, sizeof(unsigned char)*cociente_size);
            cociente[cociente_size-1] = conv / UCHAR_MAX; //Gardamos o resto
            conv = conv % UCHAR_MAX; //Como conv vai ser o noso seguinte byte, facemos a division enteira e gardamos o resultado como valor de partida
        }
        i++;
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

bignum sub(bignum a, bignum b)
{
}

bignum mult(bignum a, bignum b)
{
}

/*bignum remainder(bignum a, bignum b)
{
}*/

bignum fact(bignum n)
{
}

/*bignum div(bignum a, bignum b, bignum n)
{
}*/