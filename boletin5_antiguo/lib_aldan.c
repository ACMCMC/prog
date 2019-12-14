#include "lib_aldan.h"

void invertir_signo(bignum *n)
{
    if (n->signo == 0)
    {
        n->signo = -1;
    }
    else
    {
        n->signo = 0;
    }
}

int comparar_magnitud(bignum a, bignum b) //Devuelve 1 si el valor absoluto de a es mayor que el de b, -1 si es menor, y 0 si son iguales
{
    if (a.tam > b.tam)
    {
        return 1;
    }
    else if (b.tam > a.tam)
    {
        return -1;
    }
    else if (a.val > b.val)
    {
        return 1;
    }
    else if (b.val > a.val)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparar(bignum a, bignum b)
{
    if (a.signo != b.signo)
    {
        if (a.signo == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (a.tam > b.tam)
    {
        return 1;
    }
    else if (b.tam > a.tam)
    {
        return -1;
    }
    else if (a.val > b.val)
    {
        return 1;
    }
    else if (b.val > a.val)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bignum str2bignum(char *str)
{
    bignum num;                                                                      //num e o numero resultado
    num.tam = 0;                                                                     //En principio, non ten tamaño
    num.val = NULL;                                                                  //Como non ten tamaño, o vector non apunta a nada
    unsigned char *dividendo = NULL, cociente_size = strlen(str), newsize, conv = 0; //dividendo e un vector de chars que usaremos para realizar as divisions, cociente_size e o tamaño do vector, que ao principio ten a lonxitude da cadea de partida, newsize e unha variable que empregaremos para ir reducindo o tamaño do dividendo, conv e o resto da division que como maximo vai ser 255 (cabe nun char)
    int i = 0, n = 0;                                                                //Estas son variables de control

    if (strlen(str) < 1) //Se o numero non mide o suficiente, saimos con codigo de estado 1
    {
        exit(EXIT_FAILURE);
    }

    if (*str == '-') //Se o numero comeza por -, enton o signo e negativo e reducimos a lonxitude da cadea nunha unidade
    {
        num.signo = -1;
        str++;
    }
    else //Se o numero non comeza por -, enton o signo e positivo e non reducimos o tamaño
    {
        num.signo = 0;
    }

    dividendo = (unsigned char *)malloc(sizeof(unsigned char) * cociente_size); //Aloxamos o tamaño preciso para gardar o dividendo

    for (i = 0; i < cociente_size; i++) //Convertemos a cadea de caracteres a unha cadea de chars con valor numerico
    {
        dividendo[i] = str[i] - '0';
    }

    while ((cociente_size > 3) || ((cociente_size == 3) && ((dividendo[2] * 100 + dividendo[1] * 10 + dividendo[0]) >= BASE_BIGNUM))) //Realizamos o bucle mentras o dividendo sexa maior que 256
    {

        newsize = 0; //O novo tamaño do dividendo en principio e cero, e imolo ir aumentando segundo engadimos cifras
        i = 1;
        conv = dividendo[0]; //Engadimos a primeira cifra do dividendo

        while (i < cociente_size)
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
        cociente_size = newsize;
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

char *showbignum(bignum num)
{

    int i, j = 0; //j e o numero de caracteres da cadea

    char *str = NULL; //a cadea esta vacia ao principio (apunta a NULL)

    for (i = 0; i < num.tam; i++)
    { //Imos facer un bucle para pasar o bignum a texto en base 10, isto facemolo multiplicando
        str = realloc(str, sizeof(char) * j);
    }

    return str;
}

bignum add(bignum a, bignum b)
{
    bignum res;
    unsigned short res_temp;

    int i, carry = 0;

    if (comparar_magnitud(a, b) < 0)
    {
        res.tam = b.tam;
    }
    else
    {
        res.tam = a.tam;
    }

    res.val = (unsigned char *)malloc(sizeof(unsigned char) * res.tam);

    for (i = 0; (i < a.tam) && (i < b.tam); i++)
    {

        res_temp = ((unsigned short)a.val[i]) + ((unsigned short)b.val[i]) + carry;
        if (res_temp > USHRT_MAX)
        {
            res.val[i] = (unsigned char)(res_temp - USHRT_MAX);
            carry = 1;
        }
        else
        {
            carry = 0;
            res.val[i] = (unsigned char)res_temp;
        }
    }

    return res;
}

bignum sub(bignum a, bignum b)
{
}

bignum mult(bignum a, bignum b)
{
}

/*bignum remainder(bignum a, bignum b)
{
}*/

bignum fact(bignum n)
{
}

/*bignum div(bignum a, bignum b, bignum n)
{
}*/