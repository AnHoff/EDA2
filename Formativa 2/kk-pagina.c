#include <stdio.h>
#include <stdlib.h>

#define MAX_ID 2000000000
#define MAX_N 33554432

int main() {
    int quantidade, pagina, tamanho_pagina;
    scanf("%d %d %d", &quantidade, &pagina, &tamanho_pagina);

    int *frequencia = (int*)calloc(MAX_ID + 1, sizeof(int));

    int identificador;
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &identificador);
        frequencia[identificador]++;
    }

    int inicio = pagina * tamanho_pagina;
    int fim = inicio + tamanho_pagina;

    int impressos = 0;

    for (int i = 0; i <= MAX_ID && impressos < fim; i++) {
        if (frequencia[i] > 0) {
            for (int j = 0; j < frequencia[i] && impressos < fim; j++) {
                if (impressos >= inicio) {
                    printf("%d\n", i);
                }
                impressos++;
            }
        }
    }

    free(frequencia);

    return 0;
}
