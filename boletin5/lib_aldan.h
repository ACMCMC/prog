#ifndef _LIB_ALDAN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define _LIB_ALDAN_H

typedef struct
{
    int signo;
    unsigned int tam;
    unsigned char *val;
} bignum;

bignum str2bignum(char *str);

bignum add(bignum a, bignum b);

bignum sub(bignum a, bignum b);

bignum mult(bignum a, bignum b);

//bignum remainder(bignum a, bignum b);

bignum fact(bignum n);

//bignum div(bignum a, bignum b, bignum n);

#endif