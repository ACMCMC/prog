#include <stdio.h>

int factorial(int n) {    
    int valor = 1;
    if (n > 0) {    
        int i;
        for (i=1; i <=n; i++) //for (i=0; i <=n; i++)  i debe ser 1, si no estaríamos multiplicando por 0, y haciendo una iteración extra
            valor = valor * i;    
    } else {
        printf("Error factorial: el parámetro (%d) no es un entero positivo\n", n); //printf("Error factorial: el parámetro (%f) no es un entero positivo\n"); El factorial es un entero
    }
    return valor;
}

