#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"
//função que inicializa a arvore;
PONT inicializa() {
    return (NULL);
}
// função que cria um novo nó
PONT criaNovoNo(TIPOCHAVE ch) {
    PONT novoNo = (PONT) malloc(sizeof (NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return (novoNo);
}
//função que adiciona um nó

PONT adiciona(PONT raiz, PONT no) {
    if (raiz == NULL)
        return (no);
    if (no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);
    /* ignora chave igual */
    return (raiz);
}



// função que verifica se um nó consta da árvore

PONT contem(TIPOCHAVE ch, PONT raiz) {
    if (raiz == NULL) 
        return (NULL);
    if (raiz->chave == ch) 
        return (raiz);
    if (raiz->chave > ch)
        return (contem(ch, raiz->esq));
    return (contem(ch, raiz->dir));
}



// funçao que conta o numero de nós da árvore

int numeroNos(PONT raiz) {
    if (!raiz) 
        return 0;
    return (numeroNos(raiz->esq)
            + 1
            + numeroNos(raiz->dir));
}


//função que imprime a árvore

void exibirArvore(PONT raiz) {
    if (raiz != NULL) {
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        printf(")");
        exibirArvore(raiz->dir);
        
    }
}

//funçao que busca um nó e atribui o filho ao avó

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai) {
    PONT atual = raiz;
    *pai = NULL;
    while (atual) {
        if (atual->chave == ch) return (atual);
        *pai = atual;
        if (ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return (NULL);
}

PONT removeNo(PONT raiz, TIPOCHAVE ch) {
    PONT pai, no, p, q;
    no = buscaNo(raiz, ch, &pai);
    if (no == NULL) return (raiz);
    if (!no->esq || !no->dir) {
        if (!no->esq) q = no->dir;
        else q = no->esq;
    } else {
        p = no;
        q = no->esq;
        while (q->dir) {
            p = q;
            q = q->dir;
        }
        if (p != no) {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai) {
        free(no);
        return (q);
    }
    if (ch < pai->chave) pai->esq = q;
    else pai->dir = q;
    free(no);
    return (raiz);
}

