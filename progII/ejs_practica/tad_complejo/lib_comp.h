#ifndef TAD_COMP_H
#define TAD_COMP_H

typedef void * complejo;

complejo Crea(float p_real, float p_comp);
complejo Conjugado(complejo num);
complejo Suma(complejo a, complejo b);
complejo Producto(complejo a, complejo b);
float ParteReal(complejo num);
float ParteImaginaria(complejo num);

#endif