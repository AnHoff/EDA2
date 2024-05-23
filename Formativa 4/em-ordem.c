#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

no* novoNo(int dado) {
    no* nodo = (no*)malloc(sizeof(no));
    nodo->dado = dado;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

void em_ordem(no *raiz) {
    if (raiz == NULL) return;

    no *stack[100]; // Tamanho máximo da pilha (assumindo um máximo de 100 nós)
    int topo = -1;  // Índice da pilha, inicialmente vazio
    no *atual = raiz;

    while (atual != NULL || topo >= 0) {
        while (atual != NULL) {
            stack[++topo] = atual;
            atual = atual->esq;
        }

        atual = stack[topo--];
        
        printf("%d ", atual->dado);
        
        atual = atual->dir;
    }
    printf("\n");
}

// int main() {
//     no* raiz = novoNo(2);
//     raiz->esq = novoNo(5);
//     raiz->dir = novoNo(7);
//     raiz->esq->esq = novoNo(3);
//     raiz->esq->dir = novoNo(8);
//     raiz->esq->dir->esq = novoNo(4);
//     raiz->dir->esq = novoNo(1);
//     raiz->dir->esq->dir = novoNo(9);
//     raiz->dir->dir = novoNo(6);

//     em_ordem(raiz);

//     return 0;
// }
