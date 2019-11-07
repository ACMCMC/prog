/*ENUNCIADO

 Nun almacén precísase gardar os datos necesarios para os distintos artigos dispoñibles nun ficheiro
 chamado invent.dat. Para cada elemento deben rexistrarse os seguintes datos: 
    codigo (enteiro)
    nome (cadea de ata 30 caracteres)
    prezo (número real), 
    cantidade (enteiro que indica a cantidade de unidades existente).

 Escribir unha función chamada gravar_datos que poida gardar os datos de varios artigos no arquivo invent.dat.
 A escritura debe facerse en binario, gardando unha estrutura en cada operación. O código para cada artigo
 será xerado secuencialmente a partir do 1 e os restantes datos serán tecleados polo usuario, mentres que
 desexe continuar coa gravación de máis artigos. Ao final, a función devolve o número de elementos inseridos.
 Escribir unha función chamada ler_datos que cargue todos os datos do arquivo de inventario  nun vector de
 estruturas, que se lle pase como argumento.  Escribir un procedemento, co nome venta_item que reciba tres
 parámetros: o código dun elemento, o número de unidades a seren vendidas e o vector de estruturas co inventario.
 Este procedemento debe acceder no vector de estruturas ao artigo que se quere vender e amosar na pantalla
 o valor total da venda. Se a cantidade de artigos existentes é menor ca cantidade esixida para a venda,
 debe mostrar unha mensaxe indicando  que non se pode realizar a venda; noutro caso debe actualizar o número
 de unidades do artigo correspondente.

 Escribir un programa en C para probar o funcionamento das tres funcións. Antes de rematar o programa
 debe actualizarse o arquivo invent.dat.*/

 /*Autor: Aldán Creo Mariño
 Data: 5 de novembro de 2019
 Versión: 1
 Este programa calcula a distancia Hamming dunha palabra introducida polo usuario comparada coas dun
 arquivo que contén outras contraseñas, para determinar se coincide con algunha delas ou non.*/

#include "lib_aldan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define N 30

typedef struct {
    int codigo;
    char nome[N];
    float precio;
    int cantidade;
} artigo;

int gravar_datos(artigo *vector_arts, int num_arts, FILE *arq) {
    int elementos_inseridos = 0;
    for(int i = 0; i < num_arts; i++) {
        fwrite(&vector_arts[i].codigo, sizeof (vector_arts[i].codigo),1,arq);
    }
    return elementos_inseridos;
}

int ler_datos(FILE *arq, artigo *vector_artigos) {
    int i = 0;
    while(feof(arq) == 0) {
        //fscanf(arq,"%d[^,],%s[^,],%f[^,],%d[^\n]\n",&vector_artigos[i].codigo,vector_artigos[i].nome,&vector_artigos[i].precio,&vector_artigos[i].cantidade);
        i++;
    }
    return(i);
}

int venda_item(int codigo, int num_uds, artigo *vector_estruturas) {
return(vector_estruturas[codigo].precio*num_uds);
}

int main() {
    artigo vector_artigos[100];
    FILE * arq = fopen("invent.dat","r+b");

    if(arq == NULL) {
        printf("Erro abrindo a base de datos.");
        exit(1);
    }

    int num_artigos = ler_datos(arq, vector_artigos);

    fclose(arq);

    return(EXIT_SUCCESS);
}