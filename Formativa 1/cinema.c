#include <stdio.h>

#define MAX_FILEIRAS 20
#define MAX_LUGARES 25

int main() {
    int fileiras, lugares;
    char sala[MAX_FILEIRAS][MAX_LUGARES][3];

    // Leitura da quantidade de fileiras e lugares
    scanf("%d %d", &fileiras, &lugares);

    // Inicializa a sala como vazia
    for (int i = 0; i < fileiras; i++) {
        for (int j = 0; j < lugares; j++) {
            sala[i][j][0] = '-';
            sala[i][j][1] = '-';
            sala[i][j][2] = '\0'; // Terminate string
        }
    }

    // Leitura dos bilhetes
    char fileira;
    int lugar;
    while (scanf(" %c%d", &fileira, &lugar) == 2) {
        // Converte a letra da fileira para o índice correspondente na matriz
        int index_fileira = fileira - 'A';

        // Marca o lugar como ocupado
        sala[index_fileira][lugar - 1][0] = 'X';
        sala[index_fileira][lugar - 1][1] = 'X';
    }

    // Impressão do mapa da sala
    printf("  ");
    for (int i = 1; i <= lugares; i++) {
        printf("%02d ", i);
    }
    printf("\n");

    for (int i = fileiras - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < lugares; j++) {
            printf("%s ", sala[i][j]);
        }
        printf("\n");
    }

    return 0;
}
