#define EXIT_SUCCESS 0;
#include "matrizdinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{

    if (argc != 5)
    {
        printf("Debe introducir como argumentos por linea de comandos:\n\t(numero de filas inicial) (numero de filas final) (tamaño del paso) (t/m)\n");
        exit(0);
    }

    FILE *fp = fopen((argv[4][0] == 't') ? "out_trasp.txt" : "out_mult.txt", "w+");

    matrizP mat;
    matrizP mat_trasp;
    matrizP m1;
    matrizP m2;
    matrizP result;
    unsigned int n = atoi(argv[1]), n_2 = n / 2;
    long unsigned int tam_max = atoi(argv[2]), paso = atoi(argv[3]), tot_mediciones;
    unsigned int med;

    tot_mediciones = ((tam_max - n) / paso);

    printf("Se van a hacer %ld mediciones.\n", tot_mediciones);

    //printf("Filas: %d, Columnas: %d\n", nfilas(mat), ncolumnas(mat));

    /*crear(&m1, 2, 3);
    crear(&m2, 3, 2);
    crear(&result, 2, 2);
    inicializar(&m1);
    inicializar(&m2);
    printf("( ");
    for (n = 1; n <= nfilas(m1); n++)
    {
        for (n_2 = 1; n_2 <= ncolumnas(m1); n_2++)
        {
            printf("%f ", recuperar(m1, n, n_2));
        }
        printf(")\n( ");
    }

    printf("\n( ");
    for (n = 1; n <= nfilas(m2); n++)
    {
        for (n_2 = 1; n_2 <= ncolumnas(m2); n_2++)
        {
            printf("%f ", recuperar(m2, n, n_2));
        }
        printf(")\n( ");
    }

    mult(&result, m1, m2);

    printf("\n( ");
    for (n = 1; n <= nfilas(result); n++)
    {
        for (n_2 = 1; n_2 <= ncolumnas(result); n_2++)
        {
            printf("%f ", recuperar(result, n, n_2));
        }
        printf(")\n( ");
    }*/

    time_t inicio;
    time_t fin;

    if (argv[4][0] == 't')
    {
        for (med = 1; med <= tot_mediciones; (n += paso, n_2 = n / 2, med++))
        {
            //trasposicion
            printf("MED #%d\n", med);
            crear(&mat, n, n_2);
            crear(&mat_trasp, n_2, n);
            inicializar(&mat);
            inicio = clock();
            trasp(&mat_trasp, mat);
            fin = clock();
            //printf("n: %ld, f(): %ld, ini: %ld, fin: %ld, t: %lf\n", med+1, n, tiempo_inicio[med], tiempo_fin[med], (tiempo_inicio[med] - tiempo_fin[med]) / (double)CLOCKS_PER_SEC);
            liberar(&mat);
            liberar(&mat_trasp);
            fprintf(fp, "%u\t%.4lf\n", n, (fin - inicio) / (double)CLOCKS_PER_SEC);
        }
    }
    else if (argv[4][0] == 'm')
    {
        for (med = 1; med <= tot_mediciones; (n += paso, n_2 = n / 2, med++))
        {
            //multiplicacion
            printf("MED #%d\n", med);
            crear(&m1, n, n);
            crear(&m2, n, n_2);
            crear(&result, n, n_2);
            inicializar(&m1);
            inicializar(&m2);
            inicio = clock();
            mult(&result, m1, m2);
            fin = clock();
            //printf("n: %ld, f(): %ld, ini: %ld, fin: %ld, t: %lf\n", med+1, n, tiempo_inicio[med], tiempo_fin[med], (tiempo_inicio[med] - tiempo_fin[med]) / (double)CLOCKS_PER_SEC);
            liberar(&m1);
            liberar(&m2);
            liberar(&result);
            fprintf(fp, "%u\t%.4lf\n", n, (fin - inicio) / (double)CLOCKS_PER_SEC);
        }
    }
    else
    {
        printf("El cuarto argumento debe ser t (trasponer) o m (multiplicar)\n");
    }

    fclose(fp);

    return EXIT_SUCCESS;
}