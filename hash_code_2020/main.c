#include <stdio.h>
#include <stdlib.h>


typedef struct elem_lista_enlazada {
    int num;
    struct elem_lista_enlazada * siguiente;
} elem_lista_enlazada;

void anadir_en_orden (elem_lista_enlazada * ids, elem_lista_enlazada * ultimoid, int anadir);

typedef struct {
    int libros;
    int dias_registro;
    int libs_por_dia;
    elem_lista_enlazada * ids;
    elem_lista_enlazada * ultimoid;
} biblioteca;

int main(int argc, char** argv) {
    
    int tot_libros, tot_biblios, dias, i, num_leido;

    biblioteca * vec_biblios;
    
    FILE* arch = fopen("a_example.txt", "r");
    
    fscanf(arch, "%d %d %d", &tot_libros, &tot_biblios, &dias);
    
    vec_biblios = malloc(sizeof(biblioteca)*tot_biblios);

    printf("Total libros: %d, bilios: %d, dias: %d\n", tot_libros, tot_biblios, dias);

    int * punt_libs = malloc(sizeof(int)*tot_libros);

    for (i = 0; i < tot_libros; i++) {
    fscanf(arch, "%d", &(punt_libs[i]));
    printf("Punt libro %d: %d\n", i, punt_libs[i]);
    }

    for (i = 0; i < tot_biblios; i++) {
        fscanf(arch,"%d %d %d",&(vec_biblios[i].libros),&(vec_biblios[i].dias_registro),&(vec_biblios[i].libs_por_dia));
    printf("Total libros: %d, dias de registro: %d, libros_por_dia: %d\n", vec_biblios[i].libros, vec_biblios[i].dias_registro, vec_biblios[i].libs_por_dia);
            fscanf(arch, "%d", &num_leido);
        vec_biblios[i].ids = malloc(sizeof(elem_lista_enlazada));
        vec_biblios[i].ultimoid = vec_biblios[i].ids;
        vec_biblios[i].ultimoid->num = num_leido;
        vec_biblios[i].ultimoid->siguiente = NULL;
        for (int j = 1; j < vec_biblios[i].libros; j++) {
            fscanf(arch, "%d", &num_leido);
            printf("Libro %d: %d\n",j,num_leido);
            anadir_en_orden(vec_biblios[i].ids, vec_biblios[i].ultimoid, num_leido);
        }
    }


    printf("hasta aqui va\n");
    return (EXIT_SUCCESS);
}

void anadir_en_orden (elem_lista_enlazada * ids, elem_lista_enlazada * ultimoid, int anadir) {
    elem_lista_enlazada * i = ids;
    elem_lista_enlazada * anterior;
    elem_lista_enlazada * insertado;
    while( i != NULL ) {
        anterior = i;
        i = i->siguiente;
        if (i == NULL || (i->num >= anadir)) {
            insertado = malloc(sizeof(elem_lista_enlazada));
            insertado->num = anadir;
            insertado->siguiente = i;
            anterior->siguiente = insertado;
            break;
        }
    }

}