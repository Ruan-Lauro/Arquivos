#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Calc *cria_calc(){
    Calc *c = (Calc*) malloc(sizeof(Calc));
    c->prim = NULL;
    return c;
}

No *inserir_inicio(No *n, int valor) {
    No *c = (No*) malloc(sizeof(No));
    c->info = valor;
    c->prox = n;
    return c;
}

void operando(Calc *c, float valor){
   c->prim = inserir_inicio(c->prim, valor);
}

void operador(Calc *c, char op){
    c->prim = inserir_inicio(c->prim, op);
}

No *remover_inicio(No *n) {
    No *c = n->prox;
    free(n);
    return c;
}
float pop(Calc *c) {
    float valor;
    valor = c->prim->info;
    c->prim = remover_inicio(c->prim);
    return valor;
}

void libera_calc(Calc *c){
   No *n = c->prim;
    while (n != NULL) {
    No *aux = n->prox;
    free(n);
    n = aux;
    }
    free(c);
        
}

void imprimir(Calc *c){
    No *aux; // auxilia a percorrer a lista
    for(aux = c->prim; aux != NULL; aux = aux->prox){
        printf("Info = %d\n", aux->info);
    }
}

/**/