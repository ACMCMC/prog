/* Autor : Guillermo Blanco Filgueira
 * Data : 18 de novembro de 2019
 * Este programa permite traballar con enteiros maiores que os permitidos polo ordenador
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesnumeros.h"

int main(int argc, char** argv) {
    
//Declaración de variables
    bignum num1,num2,num3;
    int lonx1,lonx2,lonx3,limpar=1;
    char *valor1,*valor2,*valor3;
    
//Lectura de datos (parte do cliente)

    //PRIMEIRO NUMERO
    lonx1 = 40;
    valor1 = (char*)malloc(sizeof(char)*(lonx1));
    printf("Introduza o primeiro número (con signo +/-): ");
    fgets(valor1,lonx1,stdin);
    for(int i=0;i<lonx1;i++){
        if(valor1[i]=='\n'){
            valor1[i]='\0'; //Se o número introducido foi menor desplazamos o final da cadea
            limpar = 0; //Se este é o caso non fai falta limpar o stdin
        }
    }
    if(valor1[0]!='-' && valor1[0]!='+'){ //Se o usuario non introduciu signo, o programa introduce un +
        for(int i=lonx1-2;i>0;i--) valor1[i]=valor1[i-1];
        valor1[0]='+';
    }
    if(limpar==1){
        while(getchar()!='\n'); //Limpamos o buffer se queda algún caracter
    }

    //Hai que adaptar a funcion para que admita nums de lonxitude arbitraria
    
    //SEGUNDO NUMERO
    limpar=1;
    lonx2 = 40;
    valor2 = (char*)malloc(sizeof(char)*(lonx2));
    printf("Introduza o segundo número (con signo +/-): ");
    fgets(valor2,lonx2,stdin);
    for(int i=0;i<lonx2;i++){
        if(valor2[i]=='\n'){
            valor2[i]='\0';
            limpar=0;
        }
    }
    if(valor2[0]!='-' && valor2[0]!='+'){
        for(int i=lonx2-2;i>0;i--) valor2[i]=valor2[i-1];
        valor2[0]='+';
    }
    if(limpar==1){
        while(getchar()!='\n'); //Limpamos o buffer se queda algún caracter
    }
    //TERCEIRO NUMERO
    limpar=1;
    lonx3 = 40;
    valor3 = (char*)malloc(sizeof(char)*(lonx3));
    printf("Introduza o terceiro número (con signo +/-): ");
    fgets(valor3,lonx3,stdin);
    for(int i=0;i<lonx3;i++){
        if(valor3[i]=='\n'){
            valor3[i]='\0';
            limpar=0;
        }
    }
    if(valor3[0]!='-' && valor3[0]!='+'){
        for(int i=lonx3-2;i>0;i--) valor3[i]=valor3[i-1];
        valor3[0]='+';
    }
    if(limpar==1){
        while(getchar()!='\n'); //Limpamos o buffer se queda algún caracter
    }
//Inserción de datos
    num1 = str2bignum(valor1);
    num2 = str2bignum(valor2);
    num3 = str2bignum(valor3);
    free(valor1);
    free(valor2);
    free(valor3);
    bignum p = dividir(num1,num2,num3);
    printf("MODULO:");
    printf("\nSigno: %d\n",p.sign);
    printf("Tamaño: %d\n",p.tam);
    printf("Valor: ");
    for (int i=p.tam-1;i>=0;i--) printf("%d",p.val[i]);
    return (EXIT_SUCCESS);
}

    
