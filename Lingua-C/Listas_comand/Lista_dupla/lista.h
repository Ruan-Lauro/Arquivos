

typedef struct lista Lista;

Lista *criar();

Lista *inserir_inicio(Lista *l, int valor);
Lista *busca(Lista *l, int valor);
Lista *remover(Lista *l, int index); 
void imprimir(Lista *l);
