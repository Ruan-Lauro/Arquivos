#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

void esvaziar(Calc *c){
    No *aux;
    aux = c->prim;

    while(aux != NULL){
        c->prim = aux->prox;
        free(aux);
        aux = c->prim;
    }
}

void inverter(Calc *c){
    No *aux = NULL;
    Calc *p = cria_calc();
    Calc *q = cria_calc();
    float a;
    for(aux = c->prim; aux != NULL; aux = aux->prox){
        if(aux->info == '+' || aux->info == '-' || aux->info == '*' || aux->info == '/'){
            operador(p,aux->info);
        }else{
            operando(p,aux->info);
        }

    }

    No *au = NULL;
    esvaziar(c);

    for(au = p->prim; au != NULL; au = au->prox){
        if(au->info == '+' || au->info == '-' || au->info == '*' || au->info == '/'){
            operador(q,au->info);
        }else{
            operando(q,au->info);
        }

    }

    No *ax = NULL;

    for(ax = q->prim; ax != NULL; ax = ax->prox){
        if(ax->info == '+' || ax->info == '-' || ax->info == '*' || ax->info == '/'){
            operador(c,ax->info);
        }else{
            operando(c,ax->info);
        }

    }
    
}


float calcul(float n1, float n2, char op){
    float resultado;
    if(op == '+'){
        resultado = n1+n2;
    }else if(op == '-'){
        resultado = n1-n2;
    }else if(op == '*'){
        resultado = n1*n2;
    }else if(op == '/'){
        resultado = n1/n2;
    }else{
        return 0;
    }
    return resultado;
}

void resolucao(Calc *p){
     No *aux = NULL;
     Calc *c = cria_calc();
     Calc *e = cria_calc();
     int v = 0;
    float a,b,d, resultado;
    inverter(p);
    for(aux = p->prim; aux != NULL; aux = aux->prox){
        if(aux->info == '+' || aux->info == '-' || aux->info == '*' || aux->info == '/'){
            a = pop(p);
            b = pop(p);
            //printf("a: %f b:%f\n",a,b);
            resultado = calcul(a,b,aux->info);
            //printf("resultado: %f\n",resultado);
            d = pop(p);
            inverter(p);
            operando(p,resultado);
            inverter(p);
            aux = p->prim;
        }
    }

    if(p->prim->info =='+' || p->prim->info == '-' || p->prim->info == '*' || p->prim->info == '/'){
        resolucao(p);
    }
   
}

int main() {
    Calc *c = cria_calc();
    operando(c,1);
    operando(c,2);
    operador(c,'-');
    operando(c,1);
    operando(c,2);  //Colocar o operando
    operador(c,'+');
    operador(c,'+'); //Colocar o operador
    resolucao(c);   //Resolver o cálculo
    imprimir(c);    //Mostrar o valor

    return 0;
    
}