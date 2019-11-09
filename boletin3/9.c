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

typedef struct
{
    int codigo;
    char nome[N];
    float precio;
    int cantidade;
} artigo;

void mostrar_artigo(artigo artigo)
{
    printf("\nArtigo %d:\n\t%s, %.2f euros c/u.\n\t(%d uds.)\n", artigo.codigo, artigo.nome, artigo.precio, artigo.cantidade);
}

int gravar_datos(artigo *vector_artigos, int num_arts, FILE *arq)
{
    int elementos_inseridos = 0;
    for (int i = 0; i < num_arts; i++)
    {
        fseek(arq, 0, SEEK_END);
        fwrite(&vector_artigos[i].codigo, sizeof(int), 1, arq);
        fwrite(vector_artigos[i].nome, sizeof(vector_artigos[i].nome), 1, arq);
        fwrite(&vector_artigos[i].precio, sizeof(vector_artigos[i].precio), 1, arq);
        fwrite(&vector_artigos[i].cantidade, sizeof(vector_artigos[i].cantidade), 1, arq);
    }
    return elementos_inseridos;
}

int actualizar_artigo(artigo artigo, FILE *arq)
{
    fseek(arq, (artigo.codigo - 1) * (sizeof(artigo.cantidade) + sizeof(artigo.nome) + sizeof(artigo.codigo) + sizeof(artigo.precio)), SEEK_SET);
    fwrite(&artigo.codigo, sizeof(artigo.codigo), 1, arq);
    fwrite(artigo.nome, sizeof(artigo.nome), 1, arq);
    fwrite(&artigo.precio, sizeof(artigo.precio), 1, arq);
    fwrite(&artigo.cantidade, sizeof(artigo.cantidade), 1, arq);
    return 1;
}

int ler_datos(FILE *arq, artigo *vector_artigos)
{
    int i;
    for (i = 0; feof(arq) == 0; i++)
    {
        fread(&vector_artigos[i].codigo, sizeof(vector_artigos[i].codigo), 1, arq);
        fread(vector_artigos[i].nome, sizeof(vector_artigos[i].nome), 1, arq);
        fread(&vector_artigos[i].precio, sizeof(vector_artigos[i].precio), 1, arq);
        fread(&vector_artigos[i].cantidade, sizeof(vector_artigos[i].cantidade), 1, arq);
    }
    i--; //como a condición se comproba ao iniciar o bucle, ao chegar ó último artigo leremos un non válido, por iso o número total de artigos será unha unidade menor ó valor final de i.
    return (i);
}

int venda_item(int codigo, int num_uds, artigo *vector_estruturas,FILE *arq)
{
    if(vector_estruturas[codigo - 1].cantidade >= num_uds) {
vector_estruturas[codigo - 1].cantidade = vector_estruturas[codigo - 1].cantidade - num_uds;
actualizar_artigo(vector_estruturas[codigo-1],arq);
return (vector_estruturas[codigo - 1].precio * num_uds);
    } else {
        return -1;
    }
}

int main()
{
    artigo vector_artigos[100], artigo;
    FILE *arq = fopen("invent.dat", "r+b");
    int codigo, num_uds, prezo;

    if (arq == NULL)
    {
        printf("Erro abrindo a base de datos. Crearase unha nova base de datos.\n");
        fclose(arq);
        arq = fopen("invent.dat", "wb");
        fclose(arq);
        arq = fopen("invent.dat", "r+b");
    }

    int num_artigos = ler_datos(arq, vector_artigos);

    if (num_artigos == 0)
    {
        printf("Non hai artigos rexistrados. Por favor, introduza os datos dalgun artigo.\n");
        do
        {
            artigo.codigo = num_artigos + 1;
            printf("\n(Enter para acabar)\nIntroduza o nome do artigo: ");
            fflush(stdin);
            gets(artigo.nome);
            if (strcmp(artigo.nome, ""))
            {
                printf("Introduza o precio: ");
                scanf("%f", &artigo.precio);
                printf("Introduza o numero de unidades disponible: ");
                scanf("%d", &artigo.cantidade);
                vector_artigos[artigo.codigo - 1] = artigo;
                gravar_datos(&artigo, 1, arq);
                num_artigos++;
            };
        } while (strcmp(artigo.nome, "") || (num_artigos == 0));
        printf("\nArtigos inseridos correctamente.");
    };

    int opcion = 0;

    int exit = 0; //creamos unha variable de control para repetir o bucle do mennú principal

    do
    {
        printf("\nQue desexa facer?\n\n\t1. Listar os artigos do inventario.\n\t2. Engadir artigos.\n\t3. Vender un artigo.\n\t4. Actualizar os datos de artigos.\n\t0. Sair.\n\nComando: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 0: //sair do programa
            exit = 1;
            break;
        case 1: //listar os artigos
            for (int i = 0; i < num_artigos; i++)
            {
                mostrar_artigo(vector_artigos[i]);
            }
            break;
        case 2: //engadir artigos
            do
            {
                artigo.codigo = num_artigos + 1;
                printf("\nIntroduza o nome do artigo: ");
                fflush(stdin);
                gets(artigo.nome);
                if (strcmp(artigo.nome, ""))
                {
                    printf("Introduza o precio: ");
                    scanf("%f", &artigo.precio);
                    printf("Introduza o numero de unidades disponible: ");
                    scanf("%d", &artigo.cantidade);
                    vector_artigos[artigo.codigo - 1] = artigo;
                    gravar_datos(&artigo, 1, arq);
                    num_artigos++;
                };
            } while (strcmp(artigo.nome, ""));
            printf("\nArtigos inseridos correctamente.");
            break;
        case 3: //vender un artigo
            printf("\nIntroduza o codigo do artigo: ");
            scanf("%d", &codigo);
            printf("Introduza a cantidade: ");
            scanf("%d", &num_uds);
            if((prezo = venda_item(codigo, num_uds, vector_artigos,arq)) >= 0){
            printf("Prezo: %d euros\n", prezo);
            } else {
            printf("Erro na venda do artigo.\n");
            }
            break;
        case 4: //actualizar os datos dun ou varios artigos
            do
            {
                printf("\nIntroduza o codigo do artigo a actualizar.\n\t(0 para sair)\n\nCodigo: ");
                scanf("%d", &artigo.codigo);
                if ((artigo.codigo > 0) && (artigo.codigo <= num_artigos))
                {
                    printf("\nIntroduza o nome do artigo: ");
                    scanf("%s", artigo.nome);
                    printf("\nIntroduza o precio: ");
                    scanf("%f", &artigo.precio);
                    printf("\nIntroduza o numero de unidades disponible: ");
                    scanf("%d", &artigo.cantidade);
                    vector_artigos[artigo.codigo - 1] = artigo;
                    actualizar_artigo(artigo, arq);
                }
                else if (artigo.codigo == 0)
                {
                    printf("\nArtigos actualizados correctamente.\n");
                }
                else
                {
                    printf("\nO artigo non se atopa na base de datos, polo que non se pode actualizar.\n");
                }
            } while (artigo.codigo != 0);
            break;
        default:
            printf("Opcion non admitida.\n");
        }
    } while (exit == 0); //mostramos o menú principal mentres non seleccionemos a opcion de saida

    fclose(arq); //pechamos o arquivo

    return (EXIT_SUCCESS);
}