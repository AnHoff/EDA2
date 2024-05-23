#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* maximo(no *r) {
    if (r == NULL) {
        return NULL;
    }
    
    no* atual = r;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    
    return atual;
}

no* novoNo(int chave) {
    no* nodo = (no*)malloc(sizeof(no));
    nodo->chave = chave;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

// int main() {
//     no* raiz = novoNo(10);
//     raiz->esq = novoNo(5);
//     raiz->dir = novoNo(20);
//     raiz->esq->esq = novoNo(2);
//     raiz->esq->dir = novoNo(8);
//     raiz->dir->dir = novoNo(30);

//     no* max = maximo(raiz);
//     if (max != NULL) {
//         printf("O valor máximo na árvore é: %d\n", max->chave);
//     } else {
//         printf("A árvore está vazia.\n");
//     }

//     return 0;
// }
