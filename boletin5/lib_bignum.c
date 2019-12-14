/*Aldán Creo Mariño
*/

/*

REFERENCIAS

[1] https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/

[2] https://stackoverflow.com/questions/7983652/how-much-does-pointer-indirection-affect-efficiency

[3] https://stackoverflow.com/questions/18617620/behavior-of-realloc-when-the-new-size-is-the-same-as-the-old-one

[4] https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_bignum.h"

typedef enum
{
    maior = 1,
    igual = 0,
    menor = -1
} comparacion; //Empregamos esta enumeración para evaluar comparacións de bignums

unsigned int errobignum = ERRO_FALSE;

comparacion comparar(bignum a, bignum b)
{
    if (a.sign != b.sign) //Se o signo é distinto...
    {
        if (a.sign == positivo)
        {
            return maior; //Sendo a positivo, a > b
        }
        else
        {
            return menor; //Sendo a negativo, a < b
        }
    }
    else if (a.tam > b.tam) //Se a ten máis cifras que b, a é maior que b
    {
        return maior;
    }
    else if (b.tam > a.tam) //Se b ten máis cifras que a, a é menor que b
    {
        return menor;
    }
    else
    {
        while (a.tam > 0)
        { //Para ser máis eficientes en uso de memoria, imos empregar a.tam como unha variable contador: percorreremos o vector dos díxitos ata atopar un que sexa distinto, decrecendo a.tam (que actúa como contador)
            if (a.val[a.tam - 1] == b.val[a.tam - 1])
            {            //a primeira condición que comprobamos, tratando de ser máis eficientes, é se as dúas cifras son iguais
                a.tam--; //Decrecemos a nosa variable contador
            }
            else if (a.val[a.tam - 1] > b.val[a.tam - 1])
            {
                return (maior);
            }
            else
            { //b é maior que a
                return (menor);
            }
        }

        return igual; //se comprobamos tódalas cifras, iso é porque coinciden, e os bignums son iguais
    }
}

char *bignum2str(bignum num)
{
    char *str; //Se o signo e 1 (o num e negativo), engadimos 1 ao tamaño
    int i;

    if (num.sign == negativo)
        (i = 1, num.tam++); //Para aforrarnos unha variable extra que nos indique se debemos facer un "shift" da cadea para incluir o - ao principio, simplemente incrementamos num.tam (xa non será o tamaño real, pero non nos importa porque estamos a traballar cunha copia do bignum orixinal)
    else if (num.sign == positivo)
        i = 0; //Se o noso número é positivo, non facemos un shift
    else
        return ("#ERRO"); //Podería ser o caso de que o bignum teña asignado o signo de erro, nese caso o string que devolvemos será un de erro

    str = (char *)malloc(sizeof(char) * (num.tam + 1));
    while (i < num.tam)
    {
        str[i] = num.val[num.tam - 1 - i] + '0';
        i++;
    }

    str[i] = '\0';
    if (num.sign == negativo)
    {
        str[0] = '-';
    }

    return str;
}

bignum str2bignum(char *str)
{
    bignum num;
    int i;

    if (*str == '-')
    {
        num.sign = negativo; //O valor 1 será signo negativo
        str++;               //Incrementamos a direccion a que apunta o punteiro. Isto implica que o noso string se reduce nunha unidade, xa que comezaremos a ler a partir da posicion 1 de str
    }
    else
        num.sign = positivo;

    //Ignoramos os ceros á esquerda

    while (*str == '0')
    {
        str++;
    }

    if (*str == '\0')
    { //Se tras ignorar todolos ceros a esquerda da cadea, non nos queda nada, enton o noso numero e o 0
        num.val = (char *)malloc(sizeof(*num.val));
        num.val[0] = 0;
        num.tam = 1;
        num.sign = positivo;

        return num; //Devolvemos o 0
    }

    //O noso numero non e 0, imos convertir a cadea en orde inverso a valores do vector do noso bignum

    num.tam = strlen(str);

    num.val = (char *)malloc(sizeof(*num.val) * num.tam);

    for (i = 0; i < num.tam; i++)
    {
        if ((str[num.tam - i - 1] < '0') || (str[num.tam - i - 1] > '9'))
        { //Se o caracter que estamos a ler non e un numero, devolvemos un bignum de erro e establecemos a nosa variable global de erro
            errobignum = ERRO_CARACTERES_NON_ADMITIDOS;
            num.tam = 0;
            num.sign = erro;
            num.val = NULL;
            return (num);
        }
        else
        {
            num.val[i] = str[num.tam - i - 1] - '0'; //Restamos '0' a cada dixito de str
        }
    }

    return num;
}

bignum add(bignum a, bignum b)
{
    bignum result, *bignum_maior, *bignum_menor;
    unsigned char i, acarreo = 0;

    //Hai que comprobar cal ten o maior tamaño. Tamén poderiamos invocar de novo a esta función cos bignums ao revés, para que a sempre sexa > b, pero sería menos eficiente.
    if (a.tam >= b.tam)
    {
        bignum_maior = &a;
        bignum_menor = &b;
    }
    else
    {
        bignum_maior = &b;
        bignum_menor = &a;
    }

    if (a.sign == b.sign)
    {
        result.sign = a.sign;           //Se os signos son iguais, sumanse os módulos e o signo é o mesmo
        result.tam = bignum_maior->tam; //A suma pode ter como moito un díxito máis que o maior, que reservaremos posteriormente se nos fai falta
        result.val = (char *)malloc(sizeof(*result.val) * result.tam);

        for (i = 0; i < bignum_menor->tam; i++)
        {
            result.val[i] = (a.val[i] + b.val[i] + acarreo); //A cifra actual que gardamos é a cifra en módulo 10. A suma facémola con a e b, porque non nos importa cal é o maior xa que a suma é conmutativa, e deste xeito nos aforramos o acceso a través dunha dereferenciación, polo cal somos máis eficientes [2]
            acarreo = result.val[i] / 10;                    //O acarreo é a división enteira por 10
            result.val[i] = result.val[i] % 10;              //En vez de facer directamente o módulo, para aforrarnos repetir os cálculos, empregamos result.val[i] como un almacén temporal do resultado da multiplicación para calcular o acarreo
        }
        while (i < bignum_maior->tam)
        { //Imos sumando o resto de dixitos, que se corresponden aos do maior
            result.val[i] = (bignum_maior->val[i] + acarreo);
            acarreo = result.val[i] / 10;
            result.val[i] = result.val[i] % 10;
            i++;
        }

        if (acarreo) //Se temos un acarreo, precisamos aumentar nunha unidade o tamaño da suma e engadir ese acarreo
        {
            result.tam++;
            result.val = (char *)realloc(result.val, sizeof(*result.val) * result.tam);
            result.val[result.tam - 1] = acarreo;
        }
    }
    else
    {                           //Se os bignums son de signo oposto, haberá que facer unha resta
        if (a.sign == negativo) //temos (-a) + (+b), e polo tanto facemos b - (+ a)
        {
            a.sign = positivo;
            result = resta(b, a);
        }
        else //temos (+a) + (-b), por iso facemos a - b
        {
            b.sign = positivo;
            result = resta(a, b);
        }
    }

    return result;
}

bignum resta(bignum a, bignum b)
{
    //A función de resta é moi similar á de suma

    bignum result, *bignum_maior, *bignum_menor;
    unsigned char i, acarreo = 0;

    //Hai que comprobar cal ten o maior tamaño. Tamén poderiamos invocar de novo a esta función cos bignums ao revés, para que a sempre sexa > b, pero sería menos eficiente.
    if (comparar(a, b) == menor)
    {
        bignum_maior = &b;
        bignum_menor = &a;
    }
    else
    {
        bignum_maior = &a;
        bignum_menor = &b;
    }

    if (bignum_maior->sign == bignum_menor->sign)
    {
        result.sign = a.sign;           //Se os signos do maior e o menor coinciden, facemos a resta dos módulos, e o signo é o mesmo
        result.tam = bignum_maior->tam; //A resta pode medir como máximo o tamaño do maior
        result.val = (char *)malloc(sizeof(*result.val) * result.tam);

        for (i = 0; i < bignum_menor->tam; i++)
        {
            result.val[i] = (bignum_maior->val[i] - bignum_menor->val[i] - acarreo); //A cifra actual que gardamos é a cifra en módulo 10
            if (result.val[i] < 0)
            {
                result.val[i] += 10;
                acarreo = 1;
            }
            else
            {
                acarreo = 0;
            }
        }
        while (i < bignum_maior->tam)
        {                                                     //Imos restándolle o acarreo ao resto de dixitos, que se corresponden aos do maior
            result.val[i] = (bignum_maior->val[i] - acarreo); //A cifra actual que gardamos é a cifra en módulo 10
            if (result.val[i] < 0)
            {
                result.val[i] += 10;
                acarreo = 1;
            }
            else
            {
                acarreo = 0;
            }
            i++;
        }

        while ((result.val[i - 1] == 0) && (i > 1))
        {
            i--;
        }

        if ((i) != result.tam)
        { //Temos que restar ceros, e ainda que este bloque funcionaría independentemente de se hay 0 que borrar ou non, resulta máis eficiente incluílo nun if [3]
            result.tam = i;
            result.val = (char *)realloc(result.val, sizeof(*result.val) * result.tam);
        }
    }
    else
    {                           //Se son de signos distintos, haberá que facer unha suma
        if (a.sign == negativo) //temos (-a) - (+b), e polo tanto facemos - (a + b)
        {
            a.sign = positivo;
            result = add(b, a);
            result.sign = negativo;
        }
        else //temos (+a) - (-b), por iso facemos a + b
        {
            b.sign = positivo;
            result = add(a, b);
        }
    }

    return result;
}

bignum mult(bignum a, bignum b)
{
    bignum resultado, termo_suma;
    int i, j;
    unsigned char acarreo = 0;

    termo_suma.sign = positivo;
    termo_suma.tam = 0;
    termo_suma.val = NULL;

    resultado.tam = 0;
    resultado.val = NULL;
    resultado.sign = positivo;

    for (i = 0; i < b.tam; i++)
    {
        free(termo_suma.val);
        termo_suma.val = (unsigned char *)malloc(sizeof(*termo_suma.val) * (a.tam + i));
        for (j = 0; j < i; i++)
        { //Poderiamos tamen usar un calloc
            termo_suma.val[j] = 0;
        }
        while (j < i + a.tam)
        {
            termo_suma.val[j] = b.val[i] * a.val[j - i] + acarreo;
            acarreo = termo_suma.val[j] / 10;
            termo_suma.val[j] = termo_suma.val[j] % 10;
            j++;
        }
        if (acarreo)
        {
            termo_suma.tam = i + a.tam + 1;
            termo_suma.val = (unsigned char *)realloc(termo_suma.val, sizeof(*termo_suma.val) * (termo_suma.tam));
            termo_suma.val[termo_suma.tam - 1] = acarreo;
            acarreo = 0;
        }
        else
        {
            termo_suma.tam = i + a.tam;
        }
        resultado = add(resultado, termo_suma);
    }

    if (a.sign != b.sign)
    {
        resultado.sign = negativo;
    }

    while ((resultado.tam > 1) && (resultado.val[resultado.tam-1] == 0))(resultado.tam--, resultado.val = (char *)realloc(resultado.val,resultado.tam*sizeof(*resultado.val)));

    free(termo_suma.val);

    return resultado;
}

bignum modulo(bignum a, bignum n)
{
    bignum resultado, multiplo_diez;
    unsigned int i;

    multiplo_diez.sign = positivo;
    multiplo_diez.tam = 2;
    multiplo_diez.val = (char *) malloc(sizeof(*multiplo_diez.val)*multiplo_diez.tam);
    multiplo_diez.val[0] = 0;
    multiplo_diez.val[1] = 1;

    resultado.sign = positivo;
    resultado.tam = 1;
    resultado.val = (char *) malloc(sizeof(*resultado.val));
    resultado.val[0] = 0;


    for (i = a.tam-1; i >= 0; i--) {
        resultado = mult(resultado,multiplo_diez);
    printf("isto vai\n");
        resultado.val[0] = a.val[i];
        printf("%s\n",bignum2str(resultado));
        while (comparar(resultado, n) != menor) {
            resultado = resta(resultado,n);
        }
    }

    return resultado;
}

bignum fact(bignum n)
{
    bignum resultado, auxiliar; //Poderiamos declarar dous bignums: un que sexa 0 e outro que sexa 1, pero podemos reemplazalos por un bignum que chamamos auxiliar, que valerá 0 ou 1 segundo o que necesitemos (así aforramos memoria)

    auxiliar.sign = positivo; //Creamos un bignum que vale 1, para ir restándollo ó noso termo da multiplicación
    auxiliar.val = (char *)malloc(sizeof(*auxiliar.val));
    auxiliar.val[0] = 0; //Imos empregar un 0 como auxiliar ó principio da función
    auxiliar.tam = 1;

    if (comparar(n, auxiliar) != maior)
    {
        if (comparar(n, auxiliar) == igual)
        { //Se estamos pedindo o factorial de 0, devolvemos 1
            auxiliar.val[0] = 1;
            return (auxiliar);
        }
        else
        { //Devolvemos un bignum que vale 0 e establecemos errobignum a ERRO_FACTORIAL_NEGATIVO
            errobignum = ERRO_FACTORIAL_NEGATIVO;
            return (auxiliar);
        }
    }

    auxiliar.val[0] = 1; //A partir de aquí, o noso bignum auxiliar será 1, para restarlle 1 ao noso termo da multiplicación
    resultado = n;

    while ((n.tam > 1) || (n.val[0] > 2))
        (n = resta(n, auxiliar), resultado = mult(resultado, n)); //Empregamos a coma como o operador de evaluación secuencial

    free(auxiliar.val);

    return resultado;
}

bignum multmod(bignum a, bignum b, bignum n)
{
    return modulo(mult(a, b), n);
}