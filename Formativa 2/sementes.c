#include <stdio.h>
#include <stdlib.h>

typedef struct item_t {
    long long unsigned identifier;
    int quality_score;
} item_t;


#define element_t item_t
#define exchange(a, b) { element_t temp = a; a = b; b = temp; }


typedef struct Priority_Queue {
    int size;
    int capacity;
    element_t* array;
    int (*compare)(element_t, element_t);
} Priority_Queue;


Priority_Queue* MinPriorityQueue_create(int max_N, int (*compare)(element_t, element_t)) {
    Priority_Queue* pq = (Priority_Queue*)calloc(1, sizeof(Priority_Queue));
    pq->array = (element_t*)calloc(max_N + 1, sizeof(element_t));
    pq->size = 0;
    pq->capacity = max_N;
    pq->compare = compare;
    return pq;
}

void MinPriorityQueue_destroy(Priority_Queue* pq) {
    free(pq->array);
    free(pq);
}

void MinPriorityQueue_fix_up(Priority_Queue* pq, int k) {
    element_t* v = pq->array;
    while (k > 1 && (pq->compare)(v[k], v[k / 2])) {
        exchange(v[k / 2], v[k]);
        k = k / 2;
    }
}

void MinPriorityQueue_fix_down(Priority_Queue* pq, int k) {
    int j;
    element_t* v = pq->array;
    int size = pq->size;
    while (k * 2 <= size) {
        j = k * 2;
        if (j < size && (pq->compare)(v[j + 1], v[j]))
            j++;
        if (!(pq->compare)(v[j], v[k]))
            break;
        exchange(v[k], v[j]);
        k = j;
    }
}

void MinPriorityQueue_insert(Priority_Queue* pq, element_t element) {
    if (pq->size + 1 >= pq->capacity) {
        pq->capacity *= 2;
        pq->array = realloc(pq->array, pq->capacity * sizeof(element_t));
    }

    pq->array[++pq->size] = element;
    MinPriorityQueue_fix_up(pq, pq->size);
}

element_t MinPriorityQueue_delete_min(Priority_Queue* pq) {
    element_t element = pq->array[1];
    pq->array[1] = pq->array[pq->size--];
    MinPriorityQueue_fix_down(pq, 1);
    return element;
}

int MinPriorityQueue_size(Priority_Queue* pq) {
    return pq->size;
}


int compare_by_score(element_t a, element_t b) {
    if (a.quality_score != b.quality_score)
        return a.quality_score < b.quality_score;
    return a.identifier < b.identifier;
}

int compare_by_identifier(element_t a, element_t b) {
    return a.identifier < b.identifier;
}

int main() {
    int how_many_elements_to_print, i = 0, tmp;
    int capacity = 1000;
    item_t item;
    Priority_Queue* pq_by_score = MinPriorityQueue_create(capacity, &compare_by_score);

    scanf("%d\n", &how_many_elements_to_print);
    Priority_Queue* pq_by_identifier = MinPriorityQueue_create(how_many_elements_to_print, &compare_by_identifier);

    while (scanf("%lld %d\n", &item.identifier, &item.quality_score) != EOF) {
        MinPriorityQueue_insert(pq_by_score, item);
        ++i;
    }

    int items_length = i;
    tmp = how_many_elements_to_print;
    while (how_many_elements_to_print--) {
        item = MinPriorityQueue_delete_min(pq_by_score);
        MinPriorityQueue_insert(pq_by_identifier, item);
    }

    how_many_elements_to_print = tmp;
    while (how_many_elements_to_print--) {
        item = MinPriorityQueue_delete_min(pq_by_identifier);
        printf("%lld %d\n", item.identifier, item.quality_score);
    }

    MinPriorityQueue_destroy(pq_by_score);
    MinPriorityQueue_destroy(pq_by_identifier);

    return 0;
}
