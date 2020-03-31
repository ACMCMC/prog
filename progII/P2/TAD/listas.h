
typedef float TIPOELEMENTOLISTA;
typedef void *TNODOLISTA;
typedef void *TLISTA;

void crea(TLISTA *l);
void destruye(TLISTA *l);
TNODOLISTA primero(TLISTA l);
TNODOLISTA fin(TLISTA l);
int esVacia(TLISTA l);
void recupera(TLISTA l, TNODOLISTA p, TIPOELEMENTOLISTA *e);
int longitud(TLISTA l);
void inserta(TLISTA *l, TNODOLISTA p, TIPOELEMENTOLISTA e);
void suprime(TLISTA *l, TNODOLISTA p);
void modifica(TLISTA *l, TNODOLISTA p, TIPOELEMENTOLISTA e);
TNODOLISTA siguiente(TLISTA l, TNODOLISTA p);