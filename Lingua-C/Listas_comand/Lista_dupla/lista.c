#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct lista {
int info;
struct lista *prox;
struct lista *ant;
};


Lista *inserir_inicio(Lista *l, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

Lista *inserir_final(Lista *l, int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
}

Lista *busca(Lista *l, int valor){
    Lista *aux;
    for(Lista *p = l; p != NULL; p = p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL;
}

Lista *remover(Lista *l, int valor) {
    Lista *p = busca(l, valor);  
    if (p == NULL){
        return l;
    }
    if (l == p){
        l = p->prox;
    }else{
    p->ant->prox = p->prox;
    }
    if (p->prox != NULL){
        p->prox->ant = p->ant;
    }

    free(p);
    return l;
}

void imprimir(Lista *l) {
    Lista *p;
    for (p=l; p!=NULL; p=p->prox) {
        printf("%d\n", p->info);
    }
}



