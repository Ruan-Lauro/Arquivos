#define MAX 5

typedef struct lista Lista;

Lista *criar();

void append(Lista *l, int valor);
void insert(Lista *l, int valor);
void insert_sorted(Lista *l, int valor); // inserir ordenado
void clear(Lista *l);
int get(Lista *l, int index);
int full(Lista *l); // está cheia?
int empty(Lista *l); // está vazia?
void removel(Lista *l, int index); // remover por índice
int size(Lista *l); // retornar o tamanho da lista
void print(Lista *l); // imprimir os elementos da lista
