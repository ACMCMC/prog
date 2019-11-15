#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int signo;
    int tam;
    int *val;
} bignum;

void invertir_signo(bignum *n) {
    if(n->signo == 0) {
        n->signo = -1;
    } else {
        n->signo = 0;
    }
}

bignum str2bignum(char *str) {
    bignum num;
    int i;
    if(strlen(str) < 1) {
        exit(EXIT_FAILURE);
    }

    if(*str == '-') {
        num.signo = -1;
        i = 1;
    } else {
        num.signo = 0;
        i = 0;
    }
while (i < strlen(str)) {
    i++;
};
return num;
}

bignum add(bignum a, bignum b) {
    bignum res;
    if(a.signo == b.signo) {
        res.signo = a.signo;

        for(int i = 0; (i < a.tam) && (i < b.tam); i++) {

}
return res;
    } else {
        invertir_signo(&b);
        res = sub(a, b);
        return res;
    }
}

bignum sub(bignum a, bignum b) {

}

bignum mult(bignum a, bignum b) {

}

bignum remainder(bignum a, bignum b) {

}

bignum fact(bignum n) {

}

bignum div(bignum a, bignum b, bignum n) {

}