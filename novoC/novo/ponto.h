typedef struct conta Conta;

Conta* add (float valor, int nume);
void depositar(Conta *c,float valor);
void sacar(Conta *c, float valor);
void imprimir(Conta *c);