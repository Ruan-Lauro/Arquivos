#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct lista {
    int quant;
    int vet[MAX];
};


Lista *criar() {
    Lista *l;
    l = (Lista *) malloc(sizeof(Lista));
    if (l != NULL) {
        l->quant = 0;
    }

    return l;

}

void clear(Lista *l) {
    free(l);
}

void append(Lista *l, int valor) {
    l->vet[l->quant] = valor;
    l->quant++;
}

void insert(Lista *l, int valor) {
    for (int i = l->quant - 1; i >= 0; i--) {
        l->vet[i + 1] = l->vet[i];
    }
    l->vet[0] = valor;
    l->quant++;


}

int get(Lista *l, int index) {
   if(index < l->quant){
     return l->vet[index];
   }else{
    return 1;
   }
}

void insert_sorted(Lista *l, int valor){
    for (int i = l->quant - 1; i >= 0; i--) {
        l->vet[i + 1] = l->vet[i];
    }
    l->vet[0] = valor;
    l->quant++;
    int j, k, aux;
    for (j = 1; j < l->quant; j++) {
        aux = l->vet[j];
        k = j - 1;
        while (k >= 0 && l->vet[k] > aux) {
            l->vet[k + 1] = l->vet[k];
            k--;
        }
        l->vet[k + 1] = aux;
    }
}

int full(Lista *l){
    
    if(l->quant == 5){
        printf("\nEsta cheia\n");
    }else{
        printf("\nNao esta cheia\n");
    }

}

int empty(Lista *l){
    if(l->quant == 0){
        printf("\nEsta vazia\n");
    }else{
        printf("\nNao esta vazia\n");
    }
}

void removel(Lista *l, int index){
    int novo;
    if(index < l->quant - 1){
        for(int i = 0; i < l->quant; i++){
            if(i == index){
                l->vet[i] = l->vet[l->quant - 1];
            }
            }
            l->quant = l->quant - 1;
            int j, k, aux;
    for (j = 1; j < l->quant; j++) {
        aux = l->vet[j];
        k = j - 1;
        while (k >= 0 && l->vet[k] > aux) {
            l->vet[k + 1] = l->vet[k];
            k--;
        }
        l->vet[k + 1] = aux;
    }
    }else{
        printf("Não tem esse indice");
    }
}

int size(Lista *l){
    int a;
    a = sizeof(l->vet)/sizeof(int);
    return a;
}

void print(Lista *l){
    for(int i = 0; i < l->quant; i++){
        printf("\n%d",l->vet[i]);
    }
}


