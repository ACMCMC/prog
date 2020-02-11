#include <stdlib.h>
#include "errores.h"
typedef int tipoelem;
typedef struct celda
{
tipoelem elemento;
struct celda * siguiente;
} tipocelda ;
typedef tipocelda * puntero;
typedef puntero bolsa;
void bolsavacia(bolsa *b)
{
*b=NULL;
}
void poner (bolsa *b, tipoelem e, codigo_error * cod)
{
puntero aux;
aux=(puntero) malloc(sizeof(tipocelda));
if (aux == NULL)
 *cod = meminsu;
else
 {
 aux->elemento = e; /* equivale a *aux.elemento= e */
 aux->siguiente = *b; /* equivale a ... */
 *b = aux;
 *cod = exito;
 }

}
int esvacia (bolsa b)
{
 if (b==NULL) return 1;
 else return 0;

}
short cuantos (bolsa b, tipoelem e)
{
short cont;
puntero aux;
aux = b;
cont = 0;
while (aux!=NULL)
 {
 if (aux->elemento == e) cont++;
 aux = aux->siguiente;
 }
return cont;
}
void dest (bolsa *b)
{
puntero aux, aux2;

aux = *b;
while (aux!=NULL)
 {
 aux2 = aux;
 aux = aux->siguiente;
 free(aux2);
 *b = aux ;
 }

}