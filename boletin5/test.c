#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_bignum.h"

int main() {
    //bignum num = str2bignum("10000");
    bignum num;
    num.sign = positivo;
    num.tam = 4;
    num.val = malloc(sizeof(unsigned char)*num.tam);
    num.val[0] = 255;
    num.val[1] = 255;
    num.val[2] = 255;
    num.val[3] = 255;
    printf("Tamano: %d.\n",num.tam);
    for (int i = 0; i < num.tam; i++) {
        printf("Numero %d: %d\n",i,num.val[i]);
    }
    printf("Fin do numero.\n");
    printf("%s\n",bignum2str(num));
    return (0);
}