
typedef int TIPOELEMENTOPILA; //tipo de datos correspondiente a los elementos de la pila
                       
typedef void *TPILA;
	
void PilaVacia (TPILA *p);
void Push (TPILA * p , TIPOELEMENTOPILA e);
int EsVacia (TPILA  p );
void Cima (TPILA  p, TIPOELEMENTOPILA * pe);
void Pop(TPILA * p);

