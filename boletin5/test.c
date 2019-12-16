#include "lib_bignum.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int i, tam_errores = 0, tam_str = 1;
    char *str, **errores = NULL;
    str = malloc(sizeof(*str)*2);
    str[0] = '1';
    str[1] = '\0';

    for( (i = 0) ; i < 500 ; ( i++ , (str[tam_str-1] == '9') ? ( tam_str++ , str = realloc(str,sizeof(*str)*(tam_str+1)) , str[tam_str-1] = '0' , str[tam_str] = '\0' ) : ( str[tam_str-1]++ ) ) ) ( printf("Comprobando %s:",str) , (strcmp(bignum2str(str2bignum(str)) , str) == 0) ? ( printf(" correcto\n") ) : ( printf(" INCORRECTO, devolto %s\n",bignum2str(str2bignum(str))) , tam_errores++ , errores = realloc(errores, sizeof(*errores)*tam_errores ) , errores[tam_errores-1] = malloc( sizeof(*str)*(tam_str+1) ) , memcpy(errores[tam_errores-1] , str , sizeof(*str)*(tam_str+1)) ) );
    for ( ( i=0 , printf("\n\nRESUMO DE ERROS:\n") ) ; i < tam_errores ; i++ ) ( printf("%d.\t%s -> %s\n",i,errores[i],bignum2str(str2bignum(errores[i]))) );

    return 0;
}