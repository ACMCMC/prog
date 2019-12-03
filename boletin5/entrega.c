#include <stdio.h>
#include <stdlib.h>
#include "lib_aldan.h"

#define EXIT_SUCCESS 0

int main(){
    bignum a;
    a = str2bignum("589494346948423");

    printf("O numero e: ");

    for (int i = 0; i < a.tam; i++)
    {
        printf("%d\t",a.val[i]);
    }
    

    return(EXIT_SUCCESS);
}