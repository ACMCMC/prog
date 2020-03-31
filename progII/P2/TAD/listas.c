#include <stdio.h>
#include <stdlib.h>

typedef float TIPOELEMENTOLISTA;

typedef struct nodoLista {
    TIPOELEMENTOLISTA elemento;
    struct nodoLista * sig;
} STNODOLISTA;
typedef STNODOLISTA *TNODOLISTA;

typedef struct {
    TNODOLISTA inicio;
    int longitud;
    TNODOLISTA fin;
} STLISTA;
typedef STLISTA *TLISTA;

void crea(TLISTA *l) {
    *l = (TLISTA) malloc(sizeof (STLISTA));
    (*l)->inicio = (TNODOLISTA) malloc(sizeof (STNODOLISTA));
    (*l)->inicio->sig = NULL;
    (*l)->fin = (*l)->inicio;
    (*l)->longitud = 0;
}

void destruye(TLISTA *l) {
    (*l)->fin = (*l)->inicio;
    while ((*l)->fin != NULL) {
        (*l)->fin = (*l)->fin->sig;
        free((*l)->inicio);
        (*l)->inicio = (*l)->fin;
    }
    free(*l);
}

TNODOLISTA primero(TLISTA l) {
    return l->inicio;
}

TNODOLISTA fin(TLISTA l) {
    return l->fin;
}

int esVacia(TLISTA l) {
    if (l->longitud == 0) return 1;
    else return 0;
}

void recupera(TLISTA l, TNODOLISTA p, TIPOELEMENTOLISTA *e) {
    *e = p->sig->elemento;
}

int longitud(TLISTA l) {
    return l->longitud;
}

void inserta(TLISTA *l, TNODOLISTA p, TIPOELEMENTOLISTA e) {
    TNODOLISTA q;
    q = p->sig;
    p->sig = (STNODOLISTA *) malloc(sizeof (STNODOLISTA));
    p->sig->elemento = e;
    p->sig->sig = q;
    if (q == NULL) (*l)->fin = p->sig;
    (*l)->longitud++;
}

void suprime(TLISTA *l, TNODOLISTA p) {
    TNODOLISTA q;

    q = p->sig;
    p->sig = q->sig;
    if (p->sig == NULL)
        (*l)->fin = p;
    free(q);
    (*l)->longitud--;
}

void modifica(TLISTA *l, TNODOLISTA p, TIPOELEMENTOLISTA e) {
    p->sig->elemento = e;
}

TNODOLISTA siguiente(TLISTA l, TNODOLISTA p) {
    return p->sig;
}