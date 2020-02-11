#ifndef TAD_COMP_H
#define TAD_COMP_H

typedef void * complejo;

complejo Crea(float,float);
complejo Conjugado(complejo);
complejo Suma(complejo, complejo);
complejo Producto(complejo, complejo);
float ParteReal(complejo);
float ParteImaginaria(complejo);

#endif