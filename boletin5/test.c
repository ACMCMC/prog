#include "lib_bignum.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, tam_errores = 0, tam_str = 1;
    char *str, **errores = NULL;

    for( (i = 0) ; i < 500 ; ( i++ , (str[tam_str-1] == '9') ? () : () ) ) ( (strcmp(bignum2str(str2bignum(str)) , str) == 0) ? ( printf(" correcto\n") ) : ( printf(" INCORRECTO, devolto %s\n",bignum2str(str2bignum(str))) , tam_errores++ , errores = realloc(errores, sizeof(*errores)*tam_errores ) , errores[tam_errores-1] = malloc( sizeof(*str)*(tam_str+1) ) ) );

    return 0;
}