#include <stdio.h> //Aparece un warning que nos avisa de su declaración implícita

int absoluto(int n);
float potencia(int base, int exponente) { //int potencia(int base, int exponente) {     La función debe devolver un float, por el último caso de prueba
    if (base == 0 && exponente == 0)  //Esta es la indeterminacion de los casos de prueba, el valor devuelto es uno cualquiera
        printf("Indeterminacion, 0^0.\n");
    int valor = 1;
    int i;
    for (i=1; i <= absoluto(exponente); i++)
        valor = valor * base;
    return (exponente < 0)? (1/((float)valor)) : valor; //return (exponente < 0)? 1/valor : valor; Estamos casteando valores a int, lo cual conlleva pérdida de información
}

int absoluto(int n) {
    return (n<0)? -1*n : n; //return (n<0)? n : n; Si el numero es negativo, debemos devolver su inverso
}