#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* remover(no* r, int x) {
    if (r == NULL) {
        return NULL; // A chave não está na árvore
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        // Nó encontrado
        if (r->esq == NULL) {
            no* temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no* temp = r->esq;
            free(r);
            return temp;
        } else {
            no* paiSubstituto = r;
            no* substituto = r->esq;

            while (substituto->dir != NULL) {
                paiSubstituto = substituto;
                substituto = substituto->dir;
            }

            r->chave = substituto->chave;

            // Ajusta os ponteiros do pai do substituto
            if (paiSubstituto->dir == substituto) {
                paiSubstituto->dir = substituto->esq;
            } else {
                paiSubstituto->esq = substituto->esq;
            }

            free(substituto);
        }
    }
    return r;
}

no* inserir(no* r, int x) {
    if (r == NULL) {
        no* novo = (no*)malloc(sizeof(no));
        novo->chave = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else {
        r->dir = inserir(r->dir, x);
    }
    return r;
}

void imprimir(no* r) {
    if (r != NULL) {
        imprimir(r->esq);
        printf("%d ", r->chave);
        imprimir(r->dir);
    }
}

// int main() {
//     no* raiz = NULL;
//     raiz = inserir(raiz, 50);
//     raiz = inserir(raiz, 30);
//     raiz = inserir(raiz, 70);
//     raiz = inserir(raiz, 20);
//     raiz = inserir(raiz, 40);
//     raiz = inserir(raiz, 60);
//     raiz = inserir(raiz, 80);

//     printf("Árvore original: ");
//     imprimir(raiz);
//     printf("\n");

//     raiz = remover(raiz, 50);

//     printf("Árvore após remover 50: ");
//     imprimir(raiz);
//     printf("\n");

//     return 0;
// }
