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

void mostrar_artigo(artigo artigo) {
    printf("O artigo %d e un %s, que costa %f. Hai %d unidades.\n", artigo.codigo,artigo.nome,artigo.precio,artigo.cantidade);
}

int gravar_datos(artigo *vector_artigos, int num_arts, FILE *arq) {
    int elementos_inseridos = 0;
    for(int i = 0; i < num_arts; i++) {
        fwrite(&vector_artigos[i].codigo, sizeof (vector_artigos[i].codigo),1,arq);
        fwrite(vector_artigos[i].nome, sizeof (vector_artigos[i].nome),1,arq);
        fwrite(&vector_artigos[i].precio, sizeof (vector_artigos[i].precio),1,arq);
        fwrite(&vector_artigos[i].cantidade, sizeof (vector_artigos[i].cantidade),1,arq);
    }
    return elementos_inseridos;
}

int ler_datos(FILE *arq, artigo *vector_artigos) {
    int i = 0;
    while(feof(arq) == 0) {
        fread(&vector_artigos[i].codigo, sizeof (vector_artigos[i].codigo),1,arq);
        fread(vector_artigos[i].nome, sizeof (vector_artigos[i].nome),1,arq);
        fread(&vector_artigos[i].precio, sizeof (vector_artigos[i].precio),1,arq);
        fread(&vector_artigos[i].cantidade, sizeof (vector_artigos[i].cantidade),1,arq);
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

    /*vector_artigos[0].codigo = 1;
    vector_artigos[0].nome[0] = 'A';
    vector_artigos[0].nome[1] = 'L';
    vector_artigos[0].nome[2] = 'S';
    vector_artigos[0].nome[3] = 'A';
    vector_artigos[0].nome[4] = 'C';
    vector_artigos[0].nome[5] = '\0';
    vector_artigos[0].precio = 1.45;
    vector_artigos[0].cantidade = 3;

    vector_artigos[1].codigo = 2;
    vector_artigos[1].nome[0] = 'G';
    vector_artigos[1].nome[1] = 'H';
    vector_artigos[1].nome[2] = 'D';
    vector_artigos[1].nome[3] = 'Q';
    vector_artigos[1].nome[4] = 'L';
    vector_artigos[1].nome[5] = '\0';
    vector_artigos[1].precio = 1.43;
    vector_artigos[1].cantidade = 5;*/


    //gravar_datos(vector_artigos,2,arq);

    int num_artigos = ler_datos(arq, vector_artigos);

    for(int i = 0; i<2; i++) {
        mostrar_artigo(vector_artigos[i]);
    }

    int opcion = 0;

    while (1) {
        printf("Que desexa facer?\n\n\t1. Mostrar os artigos do inventario.\n\t2. Introducir os datos dun novo artigo.\n\t3. Vender un artigo.\n\t0. Sair.");
        getchar();
        scanf("%d",&opcion);
        switch (opcion) {
            case 0:
            break;
            case 1:
            break;
            case 2:
            break;
            default:
            printf("Opcion non admitida.\n");
        }
    }

    fclose(arq);

    return(EXIT_SUCCESS);
}