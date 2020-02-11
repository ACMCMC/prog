#include "lib_comp.h"

typedef struct {
    float p_real;
    float p_comp;
} struct_comp;

typedef struct_comp * puntero_comp;
typedef puntero_comp complejo;

complejo Crea(float p_real, float p_comp) {
    complejo num = (puntero_comp) malloc(sizeof(struct_comp));
    num->p_real = p_real;
    num->p_comp = p_comp;
    return num;
}

complejo Conjugado(complejo num) {
    complejo conj = Crea(num->p_real, num->p_comp*(-1));
    return conj;
}

complejo Suma(complejo a, complejo b) {
    return Crea(a->p_real+b->p_real, a->p_comp+b->p_comp);
}

complejo Producto(complejo a, complejo b) {
    return Crea(a->p_real*b->p_real, a->p_comp*b->p_comp);
}

float ParteReal(complejo num) {
    return num->p_real;
}

float ParteImaginaria(complejo num) {
    return num->p_comp;
}