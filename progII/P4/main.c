#include <stdlib.h>
#include <stdio.h>
#include "matrizdinamica.h"
#include <math.h>
#define TAM_TOTAL_PROGRESO 20

void imprimir(matrizD m1)
{
    int i, j;
    if (m1 != NULL)
    {
        for (i = 1; i <= nfilas(m1); i++)
        {
            for (j = 1; j <= ncolumnas(m1); j++)
            {
                printf("%f\t", recuperar(m1, i, j));
            }
            printf("\n");
        }
    }
}

void setProgress(float porcentaje, int tam_total, char* cadena_texto) {
    int i, max;

    max = (porcentaje / 100.0) * tam_total;

    setbuf(stdout, NULL); //Deshabilidamos el búfer de salida para poder mostrar el progreso
    fprintf(stdout,"\r%c[2K[", 27);
    for (i = 1; i <= max; i++) {
        fprintf(stdout,"#");
    }
    while (i <= tam_total) {
        fprintf(stdout," ");
        i++;
    }
    fprintf(stdout,"] %d%%: %s...",(int) porcentaje, cadena_texto);
}

int main(int argc, char** argv) {
    matrizD a;
    //crear(&a,4,4);
    //inicializar(&a);
    matrizD b;
    //crear(&b,4,4);
    //inicializar(&b);
    matrizD result_estandar;
    matrizD result_div_venceras;

    int tam, tam_max, pasos;
    float porcentaje = 0, paso_porcentaje;

    if (argc > 1) {
        tam_max = atoi(argv[2]);
    } else {
        tam_max = 512;
    }

    pasos = log(tam_max)/log(2);
    paso_porcentaje = 100.0/(float) pasos;

    printf("Se van a hacer %d pasos.\n",pasos);

    for (tam = 2; tam <= tam_max; tam*=2) {
        setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Creando matriz");
        crear(&a,tam,tam);
        inicializar(&a);
        crear(&b,tam,tam);
        inicializar(&b);
        crear(&result_estandar,tam,tam);
        crear(&result_div_venceras,tam,tam);
        setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Ejecutando multiplicacion estandar");
        mult(&result_estandar,a,b);
        setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Ejecutando multiplicacion por divide y venceras");
        mult_divide_venceras(&result_div_venceras,a,b);
        setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Comprobando que sean iguales");
        if (!matricesIguales(result_estandar, result_div_venceras)) {
            printf("\nERROR. RESULTADOS DIFERENTES.\n");
            return(0);
        }
        setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Liberando matrices");
        
        liberar(&a);
        liberar(&b);
        liberar(&result_estandar);
        liberar(&result_div_venceras);

        porcentaje += paso_porcentaje; //Incrementamos el porcentaje
    }
    setProgress(porcentaje, TAM_TOTAL_PROGRESO, "Completado");

    printf("\nSon iguales.\n");
}