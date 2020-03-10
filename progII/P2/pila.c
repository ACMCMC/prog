#include <stdlib.h>
#include <stdio.h>


typedef int TIPOELEMENTOPILA; //tipo de datos correspondiente a los elementos de la pila

typedef struct  pila 	{	TIPOELEMENTOPILA dato;
                       struct pila *sig;	} STPILA;
                       
typedef STPILA *TPILA;




void PilaVacia (TPILA *p)
{
*p = NULL;	/*Valor NULO en un puntero, para indicar que la pila est� vac�a. */
}

 


void Push(TPILA * p , TIPOELEMENTOPILA e)
{
TPILA q;
q= (TPILA) malloc (sizeof(STPILA));
q->dato = e ;
q->sig = *p ;
*p = q;
}



int EsVacia (TPILA  p )
{
if (p == NULL)
	return 1;
else return 0;
   }



void Cima (TPILA  p, TIPOELEMENTOPILA * pe)
{
int respuesta; 
respuesta = EsVacia(p);
if (respuesta == 1) 
printf ("ERROR, la pila no tiene elementos\n");
else	*pe = p->dato;
}

 

void Pop(TPILA * p)
{ 
TPILA q;
int respuesta; 

respuesta = EsVacia(*p);
if (respuesta==1)
   printf("ERROR, ....\n");
else
{  
q = *p;
*p = (*p)->sig;
free(q);
}

}

