struct no {
    int info;
    struct no *prox;
};
typedef struct no No;

struct fila {
    No *ini, *fim;
};
typedef struct fila Fila;

typedef struct fila Fila;

Fila *cria();
void enqueue(Fila *f, int valor);
int dequeue(Fila *f);
void liberar(Fila *f);
void imprimir(Fila *f);
