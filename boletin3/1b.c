/*Autor: Aldán Creo Mariño
Data: 16 de setembro de 2019
Versión: 1

Este programa devolve o máximo de dous enteiros pasados como argumentos a unha función*/

int* encontmax(int a, int b) {
int* max;
if (a >= b) {
max = &a;
} else {
max = &b;
}
return(max);
}

main() { 
int a,b;
int resultado;
printf("Dame dous valores enteiros: ");
scanf("%d %d",&a,&b);
resultado = *encontmax(a, b); 
printf("Máximo=%d\n",resultado); 
}
