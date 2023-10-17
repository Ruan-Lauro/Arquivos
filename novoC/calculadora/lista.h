#define MAX 7

struct no {
    int info;
    struct no *prox;
};
typedef struct no No;

struct calc {
    No *prim;
};
typedef struct calc Calc;

Calc *cria_calc();
void operando(Calc *c, float valor);
void operador(Calc *c, char op);
void libera_calc(Calc *c);
void imprimir(Calc *c);
float pop(Calc *c);
