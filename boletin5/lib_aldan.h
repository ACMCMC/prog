#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int signo;
    unsigned int tam;
    unsigned int *val;
} bignum;

void invertir_signo(bignum *n) {
    if(n->signo == 0) {
        n->signo = -1;
    } else {
        n->signo = 0;
    }
}

int comparar_magnitud(bignum a, bignum b) {
    if (a.tam > b.tam) {
        return 1;
    } else if (b.tam > a.tam) {
        return -1;
    } else if (a.val > b.val) {
        return 1;
    } else if (b.val > a.val) {
        return -1;
    } else {
        return 0;
    }
}

int comparar(bignum a, bignum b) {
    if (a.signo != b.signo)
    {
        if(a.signo == 0) {
            return 1;
        } else {
            return -1;
        }
    } else if (a.tam > b.tam) {
        return 1;
    } else if (b.tam > a.tam) {
        return -1;
    } else if (a.val > b.val) {
        return 1;
    } else if (b.val > a.val) {
        return -1;
    } else {
        return 0;
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

int sum_has_carry(int a, int b) {
    if ((1 + a + b) == UINT_MAX) {

    }
    else if((a/2 + b/2) >= UINT_MAX/2) { //aquí nos estamos olvidando del ultimo numero
        return 1;
    } else {
        return 0;
    }
}

bignum add(bignum a, bignum b) {
    bignum res;
    if(comparar_magnitud(a,b) >= 1) {
        res.val[0] = a.val[0]+b.val[0];
        for(res.tam = 1; res.tam <= a.tam; res.tam++) {
        res.val[res.tam] = a.val[res.tam]+b.val[res.tam];
            if(sum_has_carry(a.val[res.tam-1],b.val[res.tam-1])) { //si el int actual es uint_max, no le vamos a poder sumar el carry anterior
                res.val[i] = res.val[i] + 1;
            }
        }
    }

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