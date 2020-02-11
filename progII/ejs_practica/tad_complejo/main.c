#include "lib_comp.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, int **argv) {
    complejo a = Crea(2,4);
    printf("El complejo es: %d %di", a->p_real, a->p_comp);

    return 0;
}