#include <stdio.h>
#include "lista.h"

int main() {
    ListaCircular *l = criar();
    inserir(l,1);
    inserir(l,2);
    inserir(l,3);
    imprimir(l);
    printf("%d", busca(l,3));
    /*remover(l,2);
    imprimir(l);*/
    return 0;
}