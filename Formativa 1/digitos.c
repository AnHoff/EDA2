#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int digitos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &digitos[i]);
    }

    long long A = 0, B = 0;
    int i = 0;

    // Construindo o valor de A
    while (i < N && digitos[i] == 0) {
        i++;
    }
    while (i < N && digitos[i] != 0) {
        A = A * 10 + digitos[i];
        i++;
    }

    // Construindo o valor de B
    while (i < N && digitos[i] == 0) {
        i++;
    }
    while (i < N) {
        B = B * 10 + digitos[i];
        i++;
    }

    printf("%lld\n", A);

    return 0;
}
