/* 
 * File:   matrizdinamica.h
 * Author: mariajose
 *
 * Created on 14 de enero de 2020, 12:43
 */

#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

/*Tipo de datos de los elementos de la matriz*/
typedef float TELEMENTO;
/*tipo opaco, los detalles de implementación están ocultos al usuario*/
typedef void *matrizD;
/*Función crear: asigna memoria y devuelve la asignación a la matriz. Recibe m1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(matrizD *m1, short nfilas, short ncolumnas);
/*Función asignar: Llena una posición de la matriz con un valor. Recibe una copia de la dirección de memoria reservada para la matriz m1*/
void asignar(matrizD *m1, short fila, short columna, TELEMENTO valor);

void liberar(matrizD *m1);

TELEMENTO recuperar(matrizD m1, short fila, short columna);

short nfilas(matrizD m1);

short ncolumnas(matrizD m1);

void prodescalar(matrizD *m1, int escalar);

void inicializar(matrizD *m);

void trasp(matrizD* result, matrizD m1);

void mult(matrizD* result, matrizD m1, matrizD m2);

void inicializarSubMatriz(matrizD *submatriz, matrizD original, int cuadrante);

void mult_divide_venceras(matrizD* result, matrizD A, matrizD B);

void suma(matrizD* result, matrizD A, matrizD B);

int matricesIguales(matrizD m1, matrizD m2);

#endif /* MATRIZDINAMICA_H */
