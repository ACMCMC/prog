#ifndef BOLSA_H
#define BOLSA_H

#include "errores.h"
typedef void * bolsa; /* un tipo opaco */
typedef int tipoelem;
void bolsavacia(bolsa *b);
void poner (bolsa *b, tipoelem e, codigo_error * cod);
int esvacia (bolsa b);
short cuantos (bolsa b, tipoelem e);
void dest (bolsa *b);

#endif