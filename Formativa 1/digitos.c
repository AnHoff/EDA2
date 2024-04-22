#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int digitos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &digitos[i]);
    }

    int A = 0;
    int tamanho_atual = 0;
    for (int i = 0; i < N; i++) {
        tamanho_atual++;
        A = A * 10 + digitos[i];
        
        if (digitos[i+1] > 0 || i == N - 1) {
            printf("%d", A);
            A = 0;
            tamanho_atual = 0;
            if (i < N - 1) {
                printf(" ");
            }
        }
    }

    return 0;
}
