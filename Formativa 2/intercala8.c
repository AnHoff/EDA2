#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int lo, int hi1, int hi2) {
    int k = 0, i = lo, j = hi1 + 1;
    int* aux = (int*)calloc(hi2 - lo + 1, sizeof(int));

    while (i <= hi1 && j <= hi2) {
        if (v[i] < v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= hi1) {
        aux[k++] = v[i++];
    }

    while (j <= hi2) {
        aux[k++] = v[j++];
    }

    k = 0;
    for (i = lo; i <= hi2; ++i)
        v[i] = aux[k++];

    free(aux);
}

void merge2(int* v, int lo1, int hi1, int* w, int lo2, int hi2) {
    int k = 0, i = lo1, j = hi1 + 1;
    int* aux = (int*)calloc(hi2 - lo1 + 1, sizeof(int));

    while (i <= hi1 && j <= hi2) {
        if (v[i] < v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= hi1) {
        aux[k++] = v[i++];
    }

    while (j <= hi2) {
        aux[k++] = v[j++];
    }

    k = 0;
    for (i = lo1; i <= hi2; ++i)
        v[i] = aux[k++];

    free(aux);
}

void print_arr(int* a, int size) {
    int i = 0;
    for (; i < size - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
}

int issorted(int* itens, int len) {
    int i = 1;
    for (; i < len; ++i)
        if (itens[i] < itens[i - 1])
            return 0;
    return 1;
}

int main() {
    int i = 0, j, numbers_in_row;
    int v[8 * 100000];
    int v_idx = 0, size = 0;

    for (; i < 8; i++) {
        scanf("%d\n", &numbers_in_row);

        for (j = 0; j < numbers_in_row; j++) {
            scanf("%d\n", &v[j + v_idx]);
        }

        size += numbers_in_row;
        merge(v, 0, size - numbers_in_row - 1, size - 1);
        v_idx += numbers_in_row;
    }

    print_arr(v, size);

    return 0;
}
