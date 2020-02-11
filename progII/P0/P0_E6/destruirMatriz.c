#include "matriz.h"

void destruirMatriz(matriz *M) {
    if (M != 0) {
        free(M->datos);
        free(M);
    }
}
