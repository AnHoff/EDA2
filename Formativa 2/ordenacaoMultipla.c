#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int member_index;
    int problem_index;
    float difficulty;
} Problem;

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    Problem *problemA = (Problem *)a;
    Problem *problemB = (Problem *)b;

    // Se as dificuldades forem diferentes, ordena por dificuldade decrescente
    if (problemA->difficulty != problemB->difficulty) {
        return (problemB->difficulty - problemA->difficulty) > 0 ? 1 : -1;
    }

    // Se a dificuldade for igual, ordena por índice do membro crescente
    if (problemA->member_index != problemB->member_index) {
        return problemA->member_index - problemB->member_index;
    }

    // Se o índice do membro for igual, ordena por índice do problema crescente
    return problemA->problem_index - problemB->problem_index;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);

        Problem problems[M * N];

        // Lê as notas de todos os membros
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%f", &problems[i * N + j].difficulty);
                problems[i * N + j].member_index = i + 1;
                problems[i * N + j].problem_index = j + 1;
            }
        }

        // Ordena os problemas usando qsort
        qsort(problems, M * N, sizeof(Problem), compare);

        // Imprime os problemas ordenados
        for (int i = 0; i < M * N; i++) {
            printf("%d,%d", problems[i].member_index, problems[i].problem_index);
            if (i < M * N - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;
}
