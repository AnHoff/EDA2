#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *esq, *dir;
} No;

No* novoNo(char dado) {
    No* nodo = (No*)malloc(sizeof(No));
    nodo->dado = dado;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

No* construirArvore(char* prefixo, char* infixo, int start, int end, int* pIndex) {
    if (start > end) {
        return NULL;
    }

    char atual = prefixo[*pIndex];
    (*pIndex)++;
    No* no = novoNo(atual);

    if (start == end) {
        return no;
    }

    int iIndex;
    for (iIndex = start; iIndex <= end; iIndex++) {
        if (infixo[iIndex] == atual) {
            break;
        }
    }

    // Usar a posição encontrada para construir as sub-árvores esquerda e direita
    no->esq = construirArvore(prefixo, infixo, start, iIndex - 1, pIndex);
    no->dir = construirArvore(prefixo, infixo, iIndex + 1, end, pIndex);

    return no;
}

void posOrdem(No* raiz, char* resultado, int* index) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esq, resultado, index);
    posOrdem(raiz->dir, resultado, index);
    resultado[(*index)++] = raiz->dado;
}

int main() {
    int C;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        int N;
        char prefixo[53], infixo[53];
        scanf("%d %s %s", &N, prefixo, infixo);

        int pIndex = 0;
        No* raiz = construirArvore(prefixo, infixo, 0, N - 1, &pIndex);

        char resultado[53];
        int rIndex = 0;
        posOrdem(raiz, resultado, &rIndex);
        resultado[rIndex] = '\0';

        printf("%s\n", resultado);
    }

    return 0;
}
