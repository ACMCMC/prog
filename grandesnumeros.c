/* 
* Guillermo Blanco Filgueira
* Aldán Creo Mariño
* 25 de noviembre de 2019
*/

/*

REFERENCIAS

[1] https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandesnumeros.h"

int errobignum;

char *bignum2str(bignum num)
{
    char *str = (char *)malloc(sizeof(char) * (num.tam + 1 + num.sign)); //Se o signo e 1 (o num e negativo), engadimos 1 ao tamaño
    int i;

    for (i = num.sign; i < (num.tam + num.sign); i++)
    {
        str[i] = num.val[num.tam - 1 - i + num.sign] + '0';
    };

    str[num.tam + num.sign] = '\0';
    if (num.sign == 1)
    {
        num.val[0] = '-';
    }

    return str;
}

bignum str2bignum(char *str)
{
    bignum num;
    int i;

    if (str[0] == '-')
    {
        num.sign = 1; //O valor 1 será signo negativo
        str++;        //Incrementamos a direccion a que apunta o punteiro. Isto implica que o noso string se reduce nunha unidade, xa que comezaremos a ler a partir da posicion 1 de str
    }
    else
        num.sign = 0;

    //Ignoramos os ceros a esquerda

    while (*str == '0')
    {
        str++;
    }

    if (*str == '\0')
    { //Se tras ignorar todolos ceros a esquerda da cadea, non nos queda nada, enton o noso numero e o 0
        num.val = (char *)malloc(sizeof(*num.val));
        num.val[0] = 0;
        num.tam = 1;
        num.sign = 0;

        return num; //Devolvemos o 0
    }

    //O noso numero non e 0, imos convertir a cadea en orde inverso a valores do vector do noso bignum

    num.tam = strlen(str);

    num.val = (char *)malloc(sizeof(*num.val) * num.tam);

    for (i = 0; i < num.tam; i++)
    {
        if ((str[num.tam - i - 1] <= '0') || (str[num.tam - i - 1] >= '9'))
        { //Se o caracter que estamos a ler non e un numero, devolvemos null e establecemos a nosa variable global de erro
            errobignum = ERRO_CARACTERES_NON_ADMITIDOS;
            exit(errobignum);
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
    bignum result, *maior, *menor;
    int i;

    //Hai que comprobar cal ten o maior tamaño
    if (a.tam >= b.tam)
    {
        maior = &a;
        menor = &b;
    }
    else
    {
        maior = &b;
        menor = &a;
    }

    int acarreo = 0;
    if (a.sign == b.sign)
    {
        result.sign = a.sign;        //Se os signos son iguais, sumanse os módulos e o signo é o mesmo
        result.tam = maior->tam; //A suma pode ter como moito un díxito máis que o maior, que reservaremos posteriormente se nos fai falta
        result.val = (char *) malloc(sizeof(*result.val) * result.tam);

        for (i = 0; i < menor->tam; i++)
        {
            result.val[i] = (a.val[i] + b.val[i] + acarreo) % 10; //A cifra actual que gardamos é a cifra en módulo 10
            acarreo = (a.val[i] + b.val[i] + acarreo) / 10; //O acarreo é a división enteira por 10
        }
        while (i < maior->tam) { //Imos sumando o resto de dixitos, que se corresponden aos do maior
            result.val[i] = (maior->val[i] + acarreo) % 10;
            acarreo = (maior->val[i] + acarreo) / 10;
            i++;
        }

        if (acarreo) {
            result.tam++;
        result.val = (char *) realloc(result.val, sizeof(*result.val) * result.tam);
        result.val[result.tam - 1] = acarreo;
        }
    }
    else
    {                    //Se son distintos, haberá que facer unha resta
        if (a.sign == 1) //temos (-a) + (+b), e polo tanto facemos b - (+ a)
        {
            a.sign = 0;
            result = resta(b, a);
        }
        else //temos (+a) + (-b), por iso facemos a - b
        {
            b.sign = 0;
            result = resta(a, b);
        }
    }
    
    return result;
}

bignum resta(bignum a, bignum b)
{
    bignum result;
    bignum *maior, *menor;
    int max, acarreo = 0;
    //Hai que comprobar cal ten a maior magnitude
    if (a.tam > b.tam)
    {
        maior = &a;
        menor = &b;
    }
    else if (a.tam == b.tam)
    {
        maior = &a;
        menor = &b;
        for (int i = a.tam - 1; i >= 0; i--)
        {
            if (a.val[i] > b.val[i])
            {
                break;
            }
            else if (a.val[i] < b.val[i])
            {
                menor = &a;
                maior = &b;
            }
        }
    }
    else
    {
        maior = &b;
        menor = &a;
    }
    if (a.sign == b.sign)
    {
        if (maior == &a)
            result.sign = a.sign;
        else
        {
            if (b.sign == 0)
                result.sign = 1;
            else
                result.sign = 0;
        }
        result.tam = maior->tam; //A resta pode ter como moito o tamaño do maior
        result.val = (int *)malloc(sizeof(int) * result.tam);
        for (int i = 0; i < menor->tam; i++)
        {
            result.val[i] = (maior->val[i] - (menor->val[i] + acarreo));
            if (result.val[i] < 0)
            {
                result.val[i] += 10;
                acarreo = 1;
            }
            else
                acarreo = 0;
        }
        for (int i = menor->tam; i < maior->tam; i++)
        {
            result.val[i] = (maior->val[i] - acarreo);
            if (result.val[i] < 0)
            {
                result.val[i] += 10;
                acarreo = 1;
            }
            else
                acarreo = 0;
        }
    }
    else
    { //Se son distintos, haberá que facer unha suma
        if (a.sign == 1)
        {
            b.sign = 1;
            result = add(b, a);
        }
        else
        {
            b.sign = 0;
            result = add(a, b);
        }
    }
    //LIMPAMOS POSIBLES CEROS Á ESQUERDA
    max = result.tam - 1;
    for (int i = max; i > 0; i--)
    {
        if (result.val[i] != 0)
        {
            result.tam = i + 1;
            break;
        }
        else
            result.tam--;
    }
    //Reaxustamos a memoria
    result.val = (int *)realloc(result.val, sizeof(int) * result.tam);
    return result;
}

bignum mult(bignum a, bignum b)
{
    bignum result, holder, *maior, *menor;
    int acarreo, acarreo_prev, max;
    //O algoritmo da multiplicación funciona independentemente de que número se colla como primeiro término,
    //pero saber o maior é necesario para saber o tamaño máximo do resultado
    if (a.tam >= b.tam)
    {
        maior = &a;
        menor = &b;
    }
    else
    {
        maior = &b;
        menor = &a;
    }
    result.tam = maior->tam * 2; //O resultado terá como moito o doble de dixitos que o maior
    result.val = (int *)malloc(sizeof(int) * result.tam);
    holder.tam = maior->tam + 1;
    holder.val = (int *)malloc(sizeof(int) * holder.tam);
    for (int i = 0; i < result.tam; i++)
        result.val[i] = 0; //Limpamos a memoria por se é reciclada
    for (int i = 0; i < menor->tam; i++)
    {
        acarreo = 0;
        for (int h = 0; h < holder.tam; h++)
            holder.val[h] = 0; //Limpamos o holder
        //CALCULAMOS O RESULTADO PARCIAL
        for (int j = 0; j < maior->tam; j++)
        {
            holder.val[j] = (menor->val[i] * maior->val[j] + acarreo) % 10;
            acarreo = (menor->val[i] * maior->val[j] + acarreo) / 10;
        }
        holder.val[maior->tam] = acarreo;
        //IMPLEMENTAMOS A SUMA DO HOLDER AO RESULTADO
        acarreo = 0;
        for (int j = 0; j < holder.tam; j++)
        {
            acarreo_prev = acarreo;
            acarreo = (result.val[j + i] + holder.val[j] + acarreo) / 10;
            result.val[j + i] = (result.val[j + i] + holder.val[j] + acarreo_prev) % 10;
        }
        result.val[holder.tam + i] = acarreo;
    }
    if (a.sign == b.sign)
        result.sign = 0;
    else
        result.sign = 1;
    //LIMPAMOS POSIBLES CEROS Á ESQUERDA
    max = result.tam - 1;
    for (int i = max; i > 0; i--)
    {
        if (result.val[i] != 0)
        {
            result.tam = i + 1;
            break;
        }
        else
            result.tam--;
    }
    //Reaxustamos a memoria
    result.val = (int *)realloc(result.val, sizeof(int) * result.tam);
    free(holder.val);
    return result;
}

bignum modulo(bignum a, bignum n)
{
    bignum result, holder;
    int *borrar;
    int terminar = 0, max, acarreo = 0, signo_a, signo_n;
    holder.sign = 0;
    holder.tam = a.tam;
    holder.val = (int *)malloc(sizeof(int) * holder.tam);
    for (int i = holder.tam - 1; i >= 0; i--)
        holder.val[i] = 0; //Limpamos o holder
    result.sign = a.sign;
    result.tam = a.tam; //Como moito
    result.val = (int *)malloc(sizeof(int) * result.tam);
    for (int i = 0; i < result.tam; i++)
        result.val[i] = a.val[i]; //Insertamos o valor do dividendo no resultado
    if (result.tam == 1 && result.val[0] == 0)
        return result; //Desfacemonos do caso do 0
    //Hai que comprobar se N ten maior magnitude
    if (a.tam > n.tam)
    { //SE A É MAIS GRANDE, NON FACEMOS NADA
    }
    else if (a.tam == n.tam)
    { //SE SON IGUAIS
        for (int i = a.tam - 1; i >= 0; i--)
        { //DENDE O FINAL ATA O PRINCIPIO BUSCAMOS UN ELEMENTO MAIOR E CONTINUAMOS
            if (a.val[i] > n.val[i])
            {
                break;
            }
            else if (a.val[i] < n.val[i])
            { //SON IGUAIS E O SEGUINTE É MENOR, A É MENOR
                if (result.sign == 1)
                {
                    borrar = result.val;
                    result = add(result, n);
                    free(borrar);
                }
                if (signo_n == 1)
                {
                    borrar = result.val;
                    result = resta(n, result);
                    result.sign = 1;
                    free(borrar);
                }
                free(holder.val);
                return result;
            }
            else if (i == 0)
            { //SE TODOS SON IGUAIS E CHEGAMOS AO FINAL, O RESULTADO SERÁ 0
                result.tam = 1;
                free(result.val);
                free(holder.val);
                result.val = (int *)malloc(sizeof(int));
                result.val[0] = 0;
                return result;
            }
        }
    }
    else
    { //SE A É MENOR XA O DEVOLVEMOS
        free(holder.val);
        if (result.sign == 1)
        {
            if (n.sign == 1)
            {
                return result;
            }
            else
            {
                return add(n, result);
            }
        }
        else
        {
            if (n.sign == 1)
            {
                return add(n, result);
            }
            else
            {
                return result;
            }
        }
    }
    //SEGURO QUE A>N, PODEMOS APLICAR A FUNCION
    //DESARROLLO DA FUNCIÓN!!!!!!!!!!
    for (int i = 0; i < n.tam; i++)
        holder.val[holder.tam - n.tam + i - 1] = n.val[i]; //Rellenamos as maiores posicións do holder co divisor
    if (result.sign == 1)
    {
        signo_a = result.sign;
        result.sign = 0;
    }
    if (n.sign == 1)
    {
        signo_n = n.sign;
        n.sign = 0;
    }
    while (1)
    {
        //DETECTAMOS SE O QUE QUEDA NO RESULTADO É MENOR AO DIVISOR. SE É O CASO, REMATAMOS
        for (int i = result.tam - 1; i >= n.tam; i--)
        {
            if (result.val[i] != 0)
            {
                terminar = 0;
                break;
            }
            else
                terminar = 1;
        }
        if (terminar == 1)
        {
            for (int i = n.tam - 1; i >= 0; i++)
            {
                if (result.val[i] > n.val[i])
                {
                    terminar = 0;
                    break;
                }
                else if (result.val[i] < n.val[i])
                {
                    if (signo_a == 1)
                    {
                        max = result.tam - 1;
                        for (int i = max; i > 0; i--)
                        {
                            if (result.val[i] != 0)
                            {
                                result.tam = i + 1;
                                break;
                            }
                            else
                                result.tam--;
                        }
                        result.sign = signo_a;
                        borrar = result.val;
                        result = add(n, result);
                        free(borrar);
                    }
                    else
                    {
                        //LIMPAMOS POSIBLES CEROS Á ESQUERDA
                        max = result.tam - 1;
                        for (int i = max; i > 0; i--)
                        {
                            if (result.val[i] != 0)
                            {
                                result.tam = i + 1;
                                break;
                            }
                            else
                                result.tam--;
                        }
                    }
                    if (signo_n == 1)
                    {
                        borrar = result.val;
                        result = resta(n, result);
                        free(borrar);
                        result.sign = 1;
                    }
                    //Reaxustamos a memoria
                    result.val = (int *)realloc(result.val, sizeof(int) * result.tam);
                    return result;
                }
                else if (i == 0)
                {
                    result.sign = 0;
                    result.tam = 1;
                    free(result.val);
                    result.val = (int *)malloc(sizeof(int) * result.tam);
                    result.val[0] = 0;
                    return result;
                }
            }
        }
        //O QUE É A PROPIA FUNCIÓN, SABEMOS QUE O QUE QUEDA É >N; IMPLEMENTAR A DIVISIÓN
        //Revisamos se o holder é menor que o dividendo. Se o é facemos un shift á dereita e volvemos revisar ata poder restar
        for (int i = result.tam - 1; i >= 0; i--)
        {
            if (result.val[i] > holder.val[i])
            {
                //Implementamos a RESTA
                for (int i = 0; i < holder.tam; i++)
                {
                    result.val[i] = (result.val[i] - (holder.val[i] + acarreo));
                    if (result.val[i] < 0)
                    {
                        result.val[i] += 10;
                        acarreo = 1;
                    }
                    else
                        acarreo = 0;
                }
                break;
            }
            else if (result.val[i] < holder.val[i])
            {
                //Shift-right
                for (int i = 0; i < holder.tam - 1; i++)
                    holder.val[i] = holder.val[i + 1];
                holder.val[holder.tam - 1] = 0;
                break;
            }
        }
    }
}

bignum fact(bignum n)
{
    bignum result, counter, one;
    int *borrar;
    one.sign = 0;
    one.tam = 1;
    one.val = (int *)malloc(sizeof(int));
    one.val[0] = 1;
    if (n.sign == 1)
    {
        exit(EXIT_FAILURE); //O factorial non está definido para números negativos
    }
    if (n.tam == 1 && n.val[0] == 0)
    {
        return one;
    }
    result.sign = 0;
    result.tam = n.tam;
    result.val = (int *)malloc(sizeof(int) * result.tam);
    for (int i = 0; i < n.tam; i++)
        result.val[i] = n.val[i];
    counter.sign = 0;
    counter.tam = n.tam;
    counter.val = (int *)malloc(sizeof(int) * counter.tam);
    for (int i = 0; i < n.tam; i++)
        counter.val[i] = n.val[i];
    borrar = counter.val;
    counter = resta(counter, one);
    free(borrar);
    while (counter.tam > 1 || counter.val[0] != 0)
    {
        borrar = result.val;
        result = mult(result, counter);
        free(borrar);
        borrar = counter.val;
        counter = resta(counter, one);
        free(borrar);
    }
    free(counter.val);
    free(one.val);
    return result;
}

bignum dividir(bignum a, bignum b, bignum n)
{
    bignum result = mult(a, b);
    result = modulo(result, n);
    return result;
}