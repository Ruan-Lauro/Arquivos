#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

int retorna_valor(Fila *f){
    int resultado;
    resultado = f->ini->info;
    dequeue(f);
    return resultado;
}

int contagem(Fila *f){
    No *aux;
    int a = 0;
    for(aux = f->ini; aux != NULL; aux = aux->prox){
        a += 1;
    }
    return a;
}

void combinacao(Fila *p, Fila *c, Fila *r){
    int quant1;
    int quant2;
    quant1 = contagem(p);
    quant2 = contagem(c);
    int total;
    total = quant1 + quant2;
    for(int i = 0; i <= total; i++){
        if(p->ini != NULL){
            enqueue(r, retorna_valor(p));
        }
        if(c->ini != NULL){
            enqueue(r, retorna_valor(c));
        }
    }
}

int main() {
    Fila *p = cria();
    Fila *c = cria();
    Fila *r = cria();

    enqueue(p,1);
    enqueue(p,2);
    enqueue(p,3);
    enqueue(p,4);
    enqueue(p,5);
     

    enqueue(c,6);
    enqueue(c,7);
    enqueue(c,8);
    enqueue(c,9);
    enqueue(c,10);
    //imprimir(c);

    combinacao(p,c,r);
    imprimir(r);
    return 0;
    
}