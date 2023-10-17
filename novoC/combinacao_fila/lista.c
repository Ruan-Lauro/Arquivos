#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Fila *cria(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

No *inserir_fim(No *n, int valor) {
    No *f = (No*) malloc(sizeof(No));
    f->info = valor;
    f->prox = NULL;
    if(n != NULL){
        n->prox = f;
    }
    return f;
}
void enqueue(Fila *f, int valor) {
    f->fim = inserir_fim(f->fim, valor);
    if(f->ini == NULL){
        f->ini = f->fim;
    }   

}

No *remover_inicio(No*n){
    No *p = n->prox;
    free(n);
    return p;
}
int dequeue(Fila*f){
    int valor;
    valor = f->ini->info;
    f->ini = remover_inicio(f->ini);
    if(f->ini == NULL){
        f->fim = NULL;
    }
    return valor;
}

void liberar(Fila *f) {
    No *n = f->ini;
    while (n != NULL) {
        No *aux = n->prox;
        free(n);
        n = aux;
    }
    free(f);
}

void imprimir(Fila *f){
    No *aux;
    for(aux = f->ini; aux != NULL; aux = aux->prox){
        printf("%d ",aux->info);
    }
}


