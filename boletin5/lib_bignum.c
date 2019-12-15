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
#include <limits.h>
#include "lib_bignum.h"

#define BASE_BIGNUM (UCHAR_MAX + 1)

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
    char *str, *cad_fin, *base_256 = NULL, *termo_suma = NULL, *termo_suma_mult, *termo_suma_mult_temp = NULL, *suma; //Se o signo e 1 (o num e negativo), engadimos 1 ao tamaño
    unsigned int i, j, tam_suma, tam_str = 1, num_act, tam_base, tam_multip, carry;

    if (num.sign == negativo)
        (i = 1, tam_str++); //Para aforrarnos unha variable extra que nos indique se debemos facer un "shift" da cadea para incluir o - ao principio, simplemente incrementamos num.tam (xa non será o tamaño real, pero non nos importa porque estamos a traballar cunha copia do bignum orixinal)
    else if (num.sign == positivo)
        i = 0; //Se o noso número é positivo, non facemos un shift
    else
        return ("#ERRO"); //Podería ser o caso de que o bignum teña asignado o signo de erro, nese caso o string que devolvemos será un de erro

    //Imos obter o modulo 256 (que esta en base 1 xa) en un vector de caracteres base 10
    for ((tam_base = 1, num_act = BASE_BIGNUM); num_act > 9; tam_base++)
    {
        base_256 = (char *)realloc(base_256, sizeof(char) * (tam_base));
        base_256[tam_base - 1] = num_act % 10;
        num_act = num_act / 10;
    }


    //Temos que ir multiplicando cada elemento do vector do bignum por esta base, e ir sumando os termos sucesivos
    /*
                        2       4
              x 2       5       6
           --------------------------
                                (2)4
                        (1)2+#
                #
                1       4       4

                                (2)0
                        (1)0+#
                #
        1       2       0       0
      -------------------------------
        1       3       4       4

                                8
                        4
-------------------------------------
        4       8       0       0
-------------------------------------
        6       1       4       4
*/

    while (num.tam > 0)
    {
        num.tam--;
        free(termo_suma);

        //Converimos o elemento i-esimo do vector a un vector en b10
        for ((i = 0, num_act = num.val[num.tam]); num_act > 9; i++)
        {
            termo_suma = (char *)realloc(termo_suma, sizeof(char) * (i + 1));
            termo_suma[i] = num_act % 10;
            num_act = num_act / 10;
        }

        //Multiplicamos o que xa levabamos de antes por 256

        //tam_base es 3, porque nuestra base es {2,5,6}

        //vamos a multiplicar cada elemento de base_256 por los elementos de termo_suma_mult, esto nos va a ir dando distintos productos que acumulamos en termo_suma_mult_temp, y luego eso lo sumamos en termo_suma_mult_temp_anterior

        for (i = 0; i < tam_base; i++)
        {
            free(termo_suma_mult_temp);
            termo_suma_mult_temp = malloc(sizeof(*termo_suma_mult_temp) * (i + tam_multip - 1));
            for (j = 0; j < i; j++)
            {
printf("isto vai\n");
                termo_suma_mult_temp[j] = 0;
            }
            while (j < tam_multip)
            {
                carry = 0;
                free(termo_suma_mult_temp);
                termo_suma_mult_temp = malloc(sizeof(*termo_suma_mult_temp) * (i + tam_multip - 1));
                for (j = 0; j < i; j++)
                {
                    termo_suma_mult_temp[j] = 0;
                }
                while (j < tam_multip)
                {
                    termo_suma_mult_temp[j] =
                        termo_suma_mult[j - i] * base_256[i] + carry;
                    if (termo_suma_mult_temp[j] > 9)
                    {
                        carry = termo_suma_mult_temp[j] / 10;
                        termo_suma_mult_temp[j] = termo_suma_mult_temp[j] % 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    j++;
                }
                tam_multip = j;
                if (carry)
                {
                    termo_suma_mult_temp = realloc(termo_suma_mult_temp, sizeof(*termo_suma_mult_temp) * (j + 1));
                    termo_suma_mult_temp[j] = carry;
                        tam_multip++;
                }

                carry = 0;

                for (i = 0; i < tam_suma; i++) {
                    suma[i] = termo_suma_mult_temp[i] + suma[i] + carry;
                    if (suma[i] > 9)
                    {
                        carry = suma[i] / 10;
                        suma[i] = suma[i] - 10;
                    } else {
                        carry = 0;
                    }
                }
                while(i<tam_multip) {
                    suma[i] = termo_suma_mult_temp[i] + carry;
                    if (suma[i] > 9)
                    {
                        carry = suma[i] / 10;
                        suma[i] = suma[i] - 10;
                    } else {
                        carry = 0;
                    }
                    i++;
                }

                tam_suma = i;

                // Sumamos o que levabamos da multiplicacion con esto
            }
        }
    }

    str = (char *)malloc(sizeof(char) * (tam_str));
    while (i < num.tam)
    {
        cad_fin[i] = str[i] + '0';
        i++;
    }

    str[i] = '\0';
    if (num.sign == negativo)
    {
        str[0] = '-';
    }

    free(base_256);

    return str;
}

bignum str2bignum(char *str)
{
    bignum num;
    num.tam = 0;                                                                     //En principio, non ten tamaño
    num.val = NULL;                                                                  //Como non ten tamaño, o vector non apunta a nada
    unsigned char *dividendo = NULL, dividendo_size = strlen(str), newsize = dividendo_size, conv = 0; //dividendo e un vector de chars que usaremos para realizar as divisions, cociente_size e o tamaño do vector, que ao principio ten a lonxitude da cadea de partida, newsize e unha variable que empregaremos para ir reducindo o tamaño do dividendo, conv e o resto da division que como maximo vai ser 255 (cabe nun char)
    int i = 0, n = 0;                                                                //Estas son variables de control

    if (strlen(str) < 1) //Se o numero non mide o suficiente, saimos con codigo de estado 1
    {
        exit(EXIT_FAILURE);
    }

    if (*str == '-') //Se o numero comeza por -, enton o signo e negativo e reducimos a lonxitude da cadea nunha unidade
    {
        num.sign = negativo;
        str++;
    }
    else //Se o numero non comeza por -, enton o signo e positivo e non reducimos o tamaño
    {
        num.sign = positivo;
    }

    dividendo = (unsigned char *)malloc(sizeof(unsigned char) * dividendo_size); //Aloxamos o tamaño preciso para gardar o dividendo

    for (i = 0; i < dividendo_size; i++) //Convertemos a cadea de caracteres a unha cadea de chars con valor numerico
    {
        dividendo[i] = str[i] - '0';
    }

    while ((dividendo_size > 3) || ((dividendo_size == 3) && ((dividendo[2] * 100 + dividendo[1] * 10 + dividendo[0]) >= BASE_BIGNUM))) //Realizamos o bucle mentras o dividendo sexa maior que 256
    {

        newsize = 0; //O novo tamaño do dividendo en principio e cero, e imolo ir aumentando segundo engadimos cifras
        i = 1;
        conv = dividendo[0]; //Engadimos a primeira cifra do dividendo

        while (i < dividendo_size)
        {
            conv = conv * 10 + dividendo[i];
            if ((newsize != 0) || ((conv / BASE_BIGNUM) != 0))
            {
                newsize++;                                   //Incrementamos o tamaño do novo dividendo
                dividendo[newsize - 1] = conv / BASE_BIGNUM; //Imos gardando o cociente
                conv = conv % BASE_BIGNUM;                   //Como conv vai ser o noso seguinte byte, facemos a division enteira e gardamos o resultado como valor de partida
            }
            i++;
        }
        dividendo_size = newsize;
        /*dividendo = (unsigned char *)realloc(dividendo, sizeof(unsigned char) * cociente_size); //Este realloc permitirianos aforrar memoria, pero implica realizar multiples reallocs que influen negativamente no rendemento do programa. E mellor liberar o vector ao final.*/
        num.tam++;                                                                    //Incrementamos o tamaño do numero
        num.val = (unsigned char *)realloc(num.val, num.tam * sizeof(unsigned char)); //Facemos espacio para gardar a nova cifra en base 256
        num.val[num.tam - 1] = conv;                                                  //Gardamos o resto como a seguinte cifra do noso numero
    }

    num.tam++;                                                                    //A ultima cifra do numero e o dividendo que nos queda na ultima division
    num.val = (unsigned char *)realloc(num.val, num.tam * sizeof(unsigned char)); //Facemos espacio para gardar este ultimo dividendo
    conv = dividendo[0];                                                          //Como o dividendo e un vector de numeros en base 10, pasamolos a un unico numero
    for (i = 1; i < newsize; i++)
    {
        conv = conv * 10 + dividendo[i];
    }
    num.val[num.tam - 1] = conv;

    free(dividendo); //liberamos a memoria que xa non imos usar

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
        result.val = (unsigned char *)malloc(sizeof(*result.val) * result.tam);

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
            result.val = (unsigned char *)realloc(result.val, sizeof(*result.val) * result.tam);
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
        result.val = (unsigned char *)malloc(sizeof(*result.val) * result.tam);

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
            result.val = (unsigned char *)realloc(result.val, sizeof(*result.val) * result.tam);
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
    unsigned int i, j;
    char acarreo = 0;

    if (a.tam < b.tam)
        return (mult(b, a));

    termo_suma.sign = positivo;
    termo_suma.tam = 0;
    termo_suma.val = NULL;

    resultado.tam = 0;
    resultado.val = NULL;
    resultado.sign = positivo;

    for (i = 0; i < b.tam; i++)
    {
        free(termo_suma.val);
        termo_suma.val = (char *)malloc(sizeof(*termo_suma.val) * (a.tam + i));
        for (j = 0; j < i; j++)
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
            termo_suma.val = (char *)realloc(termo_suma.val, sizeof(*termo_suma.val) * (termo_suma.tam));
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

    while ((resultado.tam > 1) && (resultado.val[resultado.tam - 1] == 0))
        (resultado.tam--, resultado.val = (char *)realloc(resultado.val, resultado.tam * sizeof(*resultado.val)));

    free(termo_suma.val);

    return resultado;
}

bignum modulo(bignum a, bignum n)
{
    bignum resultado, multiplo_diez;
    int i;

    multiplo_diez.sign = positivo;
    multiplo_diez.tam = 2;
    multiplo_diez.val = (char *)malloc(sizeof(*multiplo_diez.val) * multiplo_diez.tam);
    multiplo_diez.val[0] = 0;
    multiplo_diez.val[1] = 1;

    resultado.sign = positivo;
    resultado.tam = 1;
    resultado.val = (char *)malloc(sizeof(*resultado.val));
    resultado.val[0] = 0;

    for (i = a.tam - 1; i >= 0; i--)
    {
        resultado = mult(resultado, multiplo_diez);
        resultado.val[0] = a.val[i];
        while (comparar(resultado, n) != menor)
        {
            resultado = resta(resultado, n);
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