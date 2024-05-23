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

void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    no* stack1[100]; // Tamanho máximo da pilha (assumindo um máximo de 100 nós)
    no* stack2[100];
    int topo1 = -1, topo2 = -1;  // Índices das pilhas

    stack1[++topo1] = raiz;

    while (topo1 >= 0) {
        no* atual = stack1[topo1--];
        stack2[++topo2] = atual;

        if (atual->esq != NULL) {
            stack1[++topo1] = atual->esq;
        }
        if (atual->dir != NULL) {
            stack1[++topo1] = atual->dir;
        }
    }

    while (topo2 >= 0) {
        printf("%d ", stack2[topo2--]->dado);
    }
    printf("\n");
}

//  int main() {
//      no* raiz = novoNo(2);
//      raiz->esq = novoNo(5);
//      raiz->dir = novoNo(7);
//      raiz->esq->esq = novoNo(3);
//      raiz->esq->dir = novoNo(8);
//      raiz->esq->dir->esq = novoNo(4);
//      raiz->dir->esq = novoNo(1);
//      raiz->dir->esq->dir = novoNo(9);
//      raiz->dir->dir = novoNo(6);

//      pos_ordem(raiz);

//      return 0;
// }
