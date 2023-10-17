#include <stdio.h>
#include "ponto.h"

int main() {
    Conta *c;
    c = add(100, 2);
    imprimir(c);

    sacar(c,50);
    imprimir(c);

    depositar(c,20);
    imprimir(c);
    return 0;
}
