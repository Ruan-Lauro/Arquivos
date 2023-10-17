#include <stdio.h>
#include "lista.h"

int main() {

    Lista *l;

    l = criar();
    append(l, 10);
    append(l, 20);
    append(l, 30);
    insert(l, 50);
    insert_sorted(l, 15);
    printf("Valor indice 1: %d\n", get(l, 1));
    full(l);
    removel(l,1);
    printf("\nO tamanho e de %d\n", size(l));
    print(l);
    return 0;
}