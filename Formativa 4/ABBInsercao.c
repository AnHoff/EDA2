#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *criar_no(int x) {
    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->chave = x;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

no *inserir(no *r, int x) {
    if (r == NULL) {
        return criar_no(x);
    }

    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    }
    else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    return r;
}

// int main() {
//     no *raiz = NULL;
    
//     raiz = inserir(raiz, 10);
//     raiz = inserir(raiz, 5);
//     raiz = inserir(raiz, 15);
//     raiz = inserir(raiz, 7);
//     raiz = inserir(raiz, 12);
//     raiz = inserir(raiz, 3);
    
//     return 0;
// }
