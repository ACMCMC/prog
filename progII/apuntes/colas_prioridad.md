# Colas con prioridad

En las colas con prioridad, cada elemento lleva asignada una prioridad. Es como si tuviéramos un vector de colas, y entonces fuéramos procesando primero la cola 1, después la 2, luego los elementos de la 3...

```C
#include "lib_cola.h"

enum {FALSE = 0; TRUE = 1} booleano;
typedef enum booleano booleano;

typedef struct {
    elem_cola * colaprimera;
} cola_prioridad;

typedef struct {
    cola * puntero_cola;
    elem_cola * siguiente;
} elem_cola;

cola_prioridad * crearColaPrioridad() {
    cola_prioridad * resultado;
    resultado = (cola_prioridad*) malloc(sizeof(cola_prioridad));
    resultado->colaprimera = NULL;
    return (resultado);
};

short es_vacia(cola_prioridad cola) {
    if (cola->colaprimera == NULL) return (TRUE);
    else return(FALSE);
}

void insertar_cola(cola_prioridad cola, int prioridad, T_ELEMENTO elemento) {
    if(es_vacia(cola)) {
        //Aquí crearíamos una cola nueva y la añadiríamos
    }
}
```