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

no *buscar_min(no *r) {
    if (r == NULL)
        return NULL;
    while (r->esq != NULL)
        r = r->esq;
    return r;
}

no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL;
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }

        no *antecessor = buscar_min(r->dir);
        r->chave = antecessor->chave;
        r->dir = remover(r->dir, antecessor->chave);
    }
    return r;
}

int main() {
    no *raiz = NULL;
    
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 3);
    
    raiz = remover(raiz, 5);
    
    return 0;
}
