#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

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
    c->numero =nume;
    return c;
}

void depositar(Conta *c,float valor){
    c->saldo += valor;
}

void sacar(Conta *c, float valor){
    c->saldo -= valor;
}

float imprimir(Conta *c){
    return c->saldo;
}