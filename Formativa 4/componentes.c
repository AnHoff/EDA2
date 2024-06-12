#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Ordena os minerais por densidade
    qsort(A, N, sizeof(int), compare);

    // Variáveis para armazenar os resultados das combinações
    int *combinedResults = (int*)malloc(N * sizeof(int));
    int combinedCount = 0;

    // Usar dois índices para simular os tubos Ta e Tb
    int i = 0; // Índice para Ta
    int j = 0; // Índice para Tb (tbIndex)

    // Array auxiliar para Tb
    int *Tb = (int*)malloc(N * sizeof(int));

    while (i < N) {
        // Transfere o menor elemento de Ta para Tb
        Tb[j++] = A[i++];

        // Tenta combinar os elementos em Tb
        while (j > 1) {
            int smallestInTb = Tb[j-2];
            int largestInTb = Tb[j-1];
            if (abs(largestInTb - smallestInTb) <= X && abs(largestInTb - smallestInTb) > 0) {
                // Combina os elementos
                combinedResults[combinedCount++] = smallestInTb + largestInTb;
                j -= 2; // Remove os elementos combinados de Tb
            } else {
                break;
            }
        }
    }

    printf("%d\n", combinedCount);
    if (combinedCount > 0) {
        for (int k = 0; k < combinedCount; k++) {
            if (k > 0) {
                printf(" ");
            }
            printf("%d", combinedResults[k]);
        }
        printf("\n");
    }

    free(A);
    free(Tb);
    free(combinedResults);
    return 0;
}
