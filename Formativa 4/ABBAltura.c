#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

int altura(no *r) {
    if (r == NULL) {
        return 0;  // Árvore vazia tem altura 0
    } else {
        int alturaEsq = altura(r->esq);
        int alturaDir = altura(r->dir);

        return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}


// int main() {
//     no *raiz = (no *)malloc(sizeof(no));
//     raiz->chave = 10;
//     raiz->esq = (no *)malloc(sizeof(no));
//     raiz->esq->chave = 5;
//     raiz->esq->esq = NULL;
//     raiz->esq->dir = NULL;
//     raiz->dir = (no *)malloc(sizeof(no));
//     raiz->dir->chave = 15;
//     raiz->dir->esq = NULL;
//     raiz->dir->dir = NULL;
    
//     int h = altura(raiz);
//     printf("Altura da arvore: %d\n", h);
    
//     free(raiz->esq);
//     free(raiz->dir);
//     free(raiz);
    
//     return 0;
// }
