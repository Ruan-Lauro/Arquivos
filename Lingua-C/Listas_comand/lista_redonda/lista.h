typedef struct lista Lista;
typedef struct ListaCircular ListaCircular;

ListaCircular *criar();
Lista *inserir(ListaCircular *l, int valor);
Lista *busca(ListaCircular *l, int valor);
Lista *remover(ListaCircular *l, int index); 
void imprimir(ListaCircular *l);
