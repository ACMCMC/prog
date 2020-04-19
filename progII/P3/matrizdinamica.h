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
typedef void *matrizP;
/*Función crear: asigna memoria y devuelve la asignación a la matriz. Recibe m1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(matrizP *m1, short nfilas, short ncolumnas);
/*Función asignar: Llena una posición de la matriz con un valor. Recibe una copia de la dirección de memoria reservada para la matriz m1*/
void asignar(matrizP *m1, short fila, short columna, TELEMENTO valor);

void liberar(matrizP *m1);

TELEMENTO recuperar(matrizP m1, short fila, short columna);

short nfilas(matrizP m1);

short ncolumnas(matrizP m1);

void prodescalar(matrizP *m1, int escalar);

void inicializar(matrizP *m);

void trasp(matrizP* result, matrizP m1);

#endif /* MATRIZDINAMICA_H */
