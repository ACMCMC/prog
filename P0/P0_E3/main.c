/*
 * PROGRAMA PARA CALCULAR EL FACTORIAL Y LA POTENCIA DE DOS NÚMEROS ENTEROS
 * PEDIDOS AL USUARIO/A POR TECLADO.
 *
 * OBJETIVO: DEPURAR USANDO LAS HERRAMIENTAS DE NETBEANS. 
 * EL PROGRAMA TIENE COMO MÍNIMO SEIS ERRORES. DOCUMENTAR LAS CORRECCIONES 
 * INTRODUCIDAS, PONIENDO UN COMENTARIO CON LA SENTENCIA INCORRECTA AL
 * LADO DE LA SENTENCIA CORREGIDA
 * 
 * PRUEBAS: USAR LOS CASOS
 * 0 0  (factorial=1, potencia=0^0, indeterminación)
 * 3 0  (factorial=6, potencia=1)
 * 0 10 (factorial=1, potencia=0)
 * 0 -2 (factorial=1, potencia=1/0=infinito)
 * 10 2 (factorial=3628800, potencia=100)
 * 2 10 (factorial=2, potencia=1024)
 * -5 1 (factorial no existe por ser negativo, potencia=-5)
 * -5 -3 (factorial no existe por ser negativo, potencia=-0.008)
 */
#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
//int potencia(int n, int m); esta declaracion está mal hecha porque necesitamos devolver un float
float potencia(int n, int m);

int main(int argc, char** argv) {
    
    int a, b;
    int f;
    //int p; p tiene que ser un float
    float p;
    
    printf("Introduce dos números enteros: ");
    //scanf("%f%d", a, &b); tenemos que dar la direccion de memoria de a, y ambos son enteros (%d)
    scanf("%d%d", &a, &b);

    f = factorial(a);
    printf("Factorial(%d) = %d\n", a, f);
    
    p = potencia(a, b);
    //printf("Potencia(%d,%d) = %d\n", a, b, p); la potencia es un float
    printf("Potencia(%d,%d) = %f\n", a, b, p);
    
    return (EXIT_SUCCESS);
}

