#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <malloc.h>

struct ListaCircular{
    struct lista *pri;
    struct lista *ult;
    int tam;
};

struct lista{
    int info;
    struct lista *prox;
};

ListaCircular *criar(){
    ListaCircular *l = (struct ListaCircular *) malloc(sizeof(ListaCircular));
    l->pri = NULL;
    l->ult = NULL;
    l->tam = 0;
    return l;
}

Lista *inserir(ListaCircular *l, int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    if(l->pri == NULL){
        l->pri = novo;
        l->ult = novo;
        novo->prox = novo;
        l->tam += 1;
        return novo;
    }
    l->ult->prox = novo;
    novo->prox = l->pri;
    l->ult = novo;

    l->tam += 1;

    return novo;
}

Lista *busca(ListaCircular *l, int valor){
    ListaCircular *p;
    Lista *aux;
    aux = p->pri->prox;
    for(p = l; p != NULL; p = aux) {
       for(aux = p->pri;!= NULL;  )
    }
    return NULL;
}

Lista *remover(ListaCircular *l, int valor){
    Lista *recebe = l->pri;
    Lista *antes = NULL;
    Lista *p = busca(l, valor);
    if(recebe != NULL){
        l->pri = recebe->prox;
        l->ult->prox = recebe->prox;
        free(p);
        l->tam -= 1;
    }else{
        return l;
    }
    antes = recebe;
    recebe = recebe->prox;
    /*while(recebe != NULL){
        if(recebe->info == valor){
            if(antes == NULL){
                l->pri = recebe->prox;
                l->ult->prox = recebe->prox;
                free(recebe);
                l->tam -= 1;
            }
           else{
            antes->prox = recebe->prox;
            free(recebe);
            l->tam -= 1;
            return recebe;
           }
        }
        antes = recebe;
        recebe = recebe->prox;
    }*/
    return 0;
}

void imprimir(ListaCircular *l) {
    Lista *p = l->pri;
if (p) {
    do {
        printf("%d\n", p->info);
        p = p->prox;
        }while (p != l->pri);
    }
}



