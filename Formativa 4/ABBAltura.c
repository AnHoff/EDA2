#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(no *r) {
    if (r == NULL) {
        return -1; // Altura de uma árvore vazia = -1
    } else {
        int altura_esq = altura(r->esq);
        int altura_dir = altura(r->dir);
        
        return 1 + max(altura_esq, altura_dir);
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
