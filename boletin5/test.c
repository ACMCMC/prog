#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_bignum.h"

int main() {
    bignum num = str2bignum("10000");
    printf("Tamaño: %d.\n",num.tam);
    for (int i = 0; i < num.tam; i++) {
        printf("Numero %d: %d\n",i,num.val[i]);
    }
    printf("Fin do numero.\n");
    printf("%s\n",bignum2str(num));
    return (0);
}