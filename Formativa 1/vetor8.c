#include <stdio.h>

int main() {
    int N, i;
    long int soma = 0;
    int contador = 0;

    // Leitura do tamanho do vetor
    scanf("%d", &N);

    // Declaração e leitura dos elementos do vetor
    int vetor[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // Cálculo da média
    int media = soma / N;

    // Impressão dos elementos maiores que a média
    for (i = 0; i < N; i++) {
        if (vetor[i] > media) {
            printf("%d", vetor[i]);
            contador++;
            if (contador < (N - 1)) {
                printf(" ");
            }
        }
    }

    // Se nenhum elemento for maior que a média, imprime 0
    if (contador == 0) {
        printf("0\n");
    }

    printf("\n");

    return 0;
}
