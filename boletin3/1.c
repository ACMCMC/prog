#define EXIT_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

float encontprom(int num1, int num2) { 
float promedio; 
promedio = (num1 + num2) / 2.0;
return(promedio);
}

int main() { 
int a,b;
float resultado;
printf("Dame dous valores enteiros: ");
scanf("%d %d",&a,&b); 
resultado = encontprom(a, b); 
printf("Promedio=%f\n",resultado); 
return(EXIT_SUCCESS);
}
