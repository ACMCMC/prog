#include "bolsa.h"

int main() {
    codigo_error * err;
    bolsa bol;
    bolsavacia(bol);
    poner(bol,12,err);
    return 0;
}