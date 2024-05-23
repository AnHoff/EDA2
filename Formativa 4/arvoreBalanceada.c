#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No* novoNo(int dado) {
    No* nodo = (No*)malloc(sizeof(No));
    nodo->dado = dado;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);
    if (alturaEsq == -1 || alturaDir == -1 || abs(alturaEsq - alturaDir) > 1) {
        return -1;
    }
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("Sim\n");
        return 0;
    }

    No* nos[N + 1];
    for (int i = 1; i <= N; i++) {
        nos[i] = novoNo(i);
    }

    for (int i = 2; i <= N; i++) {
        int pai;
        scanf("%d", &pai);
        if (nos[pai]->esq == NULL) {
            nos[pai]->esq = nos[i];
        } else {
            nos[pai]->dir = nos[i];
        }
    }

    if (altura(nos[1]) != -1) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
