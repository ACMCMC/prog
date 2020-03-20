#include "cola.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#define BONIFICACION 0.6

typedef enum
{
    TRUE = 1,
    FALSE = 0
} booleano;

TIPOELEMENTOLISTA totalBonificaciones(TLISTA listaBonificaciones)
{
    TNODOLISTA nodoSiguiente = primero(listaBonificaciones);
    TIPOELEMENTOLISTA suma = (TIPOELEMENTOLISTA)0, temporal;
    while (nodoSiguiente != fin(listaBonificaciones))
    {
        recupera(listaBonificaciones, nodoSiguiente, &temporal);
        suma += temporal;
        nodoSiguiente = siguiente(listaBonificaciones, nodoSiguiente);
    }
    return (suma);
}

void recaudarBonificaciones(TLISTA *listaBonificaciones, TIPOELEMENTOLISTA dineroARecaudar, TIPOELEMENTOLISTA *totalBonificacionesRecaudadas)
{
    TNODOLISTA nodoSiguiente;
    TNODOLISTA nodoDelMenorElemento;
    TIPOELEMENTOLISTA elemento;
    TIPOELEMENTOLISTA menorElemento;
    if (totalBonificaciones(*listaBonificaciones) >= dineroARecaudar)
    { //hay suficiente dinero para recaudar la cantidad introducida
        *totalBonificacionesRecaudadas += dineroARecaudar;
        while (dineroARecaudar > 0)
        {
            nodoSiguiente = primero(*listaBonificaciones);
            nodoDelMenorElemento = nodoSiguiente;
            recupera(*listaBonificaciones, nodoDelMenorElemento, &menorElemento);
            while (nodoSiguiente != fin(*listaBonificaciones))
            {
                recupera(*listaBonificaciones, nodoSiguiente, &elemento);
                if (elemento > menorElemento)
                {
                    nodoDelMenorElemento = nodoSiguiente;
                    menorElemento = elemento;
                }
                nodoSiguiente = siguiente(*listaBonificaciones, nodoSiguiente);
            }
            dineroARecaudar = dineroARecaudar - menorElemento;
            if (dineroARecaudar < 0)
            {
                modifica(listaBonificaciones, nodoDelMenorElemento, -1 * dineroARecaudar);
                return;
            }
            else
            {
                suprime(listaBonificaciones, nodoDelMenorElemento);
            }
        }
    }
    else
    {
        printf("No hay suficientes bonificaciones para recaudar esa cantidad.\n");
    }
}

booleano comprobarValorARecaudar(TIPOELEMENTOLISTA v)
{
    if (v > 0)
    {
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

booleano comprobarNumeroEntradas(int numeroEntradas)
{
    if (numeroEntradas > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void imprimirPrimeroCola(TCOLA cola)
{
    TIPOELEMENTOCOLA elemento;
    PrimeroCola(cola, &elemento);
    printf((EsColaVacia(cola)) ? ("\n\t\t|===============|\n\t\t|               |\n\t\t|  COLA VACIA   |\n\t\t|               |\n\t\t|===============|\n") : ("\n\t\t|===============|\n\t\t|    EN COLA    |\n\t\t|  %d  ENTRADAS  |\n\t\t|               |\n\t\t|===============|\n"), (int)elemento);
}

void imprimirListaBonificaciones(TLISTA listaBonificaciones)
{
    TNODOLISTA nodosiguiente;
    TIPOELEMENTOLISTA elemento;
    char i = 0;
    nodosiguiente = primero(listaBonificaciones);
    printf("\nLista de bonificaciones:");
    if (esVacia(listaBonificaciones))
    {
        printf("\nNo hay bonificaciones.\n");
        return;
    }
    while (nodosiguiente != fin(listaBonificaciones))
    {
        printf("\n%d. %f", i++, (recupera(listaBonificaciones, nodosiguiente, &elemento), elemento));
        nodosiguiente = siguiente(listaBonificaciones, nodosiguiente);
    }
}

void liberarListaBonificaciones(TLISTA *listaBonificaciones)
{
    /*TNODOLISTA nodoSiguiente, nodoActual = primero(*listaBonificaciones);
    while (!esVacia(*listaBonificaciones)) {
        nodoSiguiente = siguiente(*listaBonificaciones, nodoActual);
        suprime(listaBonificaciones, nodoActual);
        nodoActual = nodoSiguiente;
    }*/
    destruye(listaBonificaciones);
    *listaBonificaciones = NULL;
}

void liberarColaEspera(TCOLA *colaEspera)
{
    while (!EsColaVacia(*colaEspera))
    {
        EliminarCola(colaEspera);
    }
    free(*colaEspera);
    *colaEspera = NULL;
}

int main(int argc, char **argv)
{
    char opcion, i;
    unsigned int atendidos = 0, porAtender = 0;
    TIPOELEMENTOCOLA aux;
    TIPOELEMENTOLISTA auxLista, totalBonificacionesRecaudadas = 0;

    //inicializar la cola y la lista
    TCOLA cola = NULL;
    TLISTA lista = NULL;
    ColaVacia(&cola);
    crea(&lista);

    for (i = 1; i < argc; i++)
    {
        AnadirCola(&cola, (TIPOELEMENTOCOLA)atoi(argv[i])); //Añadimos los clientes que haga falta a la cola
        porAtender++;
    }

    do
    {
        printf("\n\nIntroduzca su opcion:\n\ta. Poner un cliente a la cola.\n\tb. Atender al primer cliente de la cola.\n\tc. Cobrar bonificaciones.\n\td. Obtener estadisticas.\n\n\ts. Salir del programa.\n\n\tOPCION: ");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a': //Añadir cliente
            printf("Introduzca el numero de entradas que desea comprar: ");
            scanf("%d", &aux);
            if (comprobarNumeroEntradas(aux) == TRUE)
            {
                AnadirCola(&cola, (TIPOELEMENTOCOLA)aux);
                porAtender++;
            }
            else
            {
                printf("\nNumero de entradas no valido.");
            }
            imprimirPrimeroCola(cola);
            break;

        case 'b': //Despachar cliente
            if (EsColaVacia(cola))
            {
                printf("La cola esta vacia.");
            }
            else
            {
                PrimeroCola(cola, &aux);
                EliminarCola(&cola);
                porAtender--;
                atendidos++;
                imprimirPrimeroCola(cola);
                //insertamos la bonificacion
                inserta(&lista, fin(lista), aux * BONIFICACION);
            }
            imprimirListaBonificaciones(lista);
            break;

        case 'c': //Cobrar bonificaciones
            printf("Cuanto desea cobrar? (max: %f): ", totalBonificaciones(lista));
            scanf(" %f", &auxLista);
            if (comprobarValorARecaudar(auxLista) == TRUE)
            {
                recaudarBonificaciones(&lista, auxLista, &totalBonificacionesRecaudadas);
                imprimirListaBonificaciones(lista);
            }
            else
            {
                printf("La cantidad introducida es incorrecta.\n");
            }
            break;

        case 'd': //Estadísticas
            printf("Atendidos: %d\nEsperando: %d\nRecaudado: %f\nPor recaudar: %f\n", atendidos, porAtender, totalBonificacionesRecaudadas, totalBonificaciones(lista));
            break;

        case 's':
            printf("Realmente desea cerrar el programa? Confirme con \"s\": ");
            scanf(" %c", &opcion);
            if (opcion == 's')
            {
                printf("\nSaliendo del programa...\n");
                liberarListaBonificaciones(&lista);
                liberarColaEspera(&cola);
            }
            break;

        default:
            printf("\n\nOpcion no valida.\n\n");
            break;
        }
    } while (opcion != 's');
}
