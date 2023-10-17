#include <stdio.h>
#include "conta.h"

int main(){
    Conta *c;
    c = add(100,2);
    depositar(c,100);
    printf("%2.f",imprimir(c));
    return 0;
}