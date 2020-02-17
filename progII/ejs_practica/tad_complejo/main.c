#include "lib_comp.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, int **argv) {
    complejo a = Crea(2,4);
    printf("El complejo es: %d %di", ParteReal(a),ParteImaginaria(a));

    return 0;
}