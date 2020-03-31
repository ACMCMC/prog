
#include <stdlib.h>
#include <stdio.h>

typedef int TIPOELEMENTOCOLA;    /* tipo de datos correspondiente a los elementos de la cola */

typedef struct nodoCola {
    TIPOELEMENTOCOLA dato;
    struct nodoCola *sig;
} STNODOCOLA;

typedef struct {
    STNODOCOLA *principio, *final;
} STCOLA;
typedef STCOLA *TCOLA;


void ColaVacia(TCOLA *q) {
    *q = (TCOLA) malloc(sizeof(STCOLA));
    (*q)->final = NULL;
    (*q)->principio = NULL;
}


int EsColaVacia(TCOLA q) {
    if ((q->final == NULL) && (q->principio == NULL)) return 1;
    else return 0;
}


void PrimeroCola(TCOLA q, TIPOELEMENTOCOLA *e) {
    int respuesta;
    respuesta = EsColaVacia(q);
    if (respuesta == 1) printf("\nERROR, la cola no tiene elementos\n");
    else *e = (q->principio)->dato;
}


void EliminarCola(TCOLA *q) {
    int respuesta;
    STNODOCOLA *aux;

    respuesta = EsColaVacia(*q);

    if (respuesta == 1) printf("\nERROR, la cola no tiene elementos\n");
    else {
        aux = (*q)->principio;
        (*q)->principio = aux->sig;
        if ((*q)->principio == NULL)
            (*q)->final = NULL;
        free(aux);
    }
}


void AnadirCola(TCOLA *q, TIPOELEMENTOCOLA e) {
    int respuesta;
    STNODOCOLA *aux;

    aux = (STNODOCOLA *) malloc(sizeof(STNODOCOLA));
    aux->dato = e;
    aux->sig = NULL;
    respuesta = EsColaVacia(*q);
    if (respuesta == 1) (*q)->principio = aux;
    else (*q)->final->sig = aux;

    (*q)->final = aux;
}  
