#include <stdio.h> 
#include <stdlib.h> 
#include "ponto.h"
			
struct conta{
    float saldo;
    int numero;
};

Conta* add (float valor, int nume) {
	Conta *c = (Conta*) malloc(sizeof(Conta));
	if(c == NULL) {
		printf("Memória insuficiente");
		exit(1);
	}
    c->saldo = valor;
    c->numero = nume;
    return c;
}

void depositar(Conta *c,float valor){
    c->saldo += valor;
}

void sacar(Conta *c, float valor){
    c->saldo -= valor;
}

void imprimir(Conta *c){
    printf("Seu valor e de %2.fR$\n",c->saldo);
}