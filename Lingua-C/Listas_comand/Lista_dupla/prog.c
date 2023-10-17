#include <stdio.h>
#include "lista.h"

int main() {
    Lista *l = NULL;
    l = inserir(l,5);
    l = inserir(l,6);
    l = inserir(l,7);
    imprimir(l);
    l = remover(l,6);
    imprimir(l);

}