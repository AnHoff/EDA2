#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000003

typedef struct Item
{
    long long id;
    long long quantity;
    struct Item *next;
} Item;

typedef struct {
    Item* head;
} Bucket;

Bucket hashtable[HASH_SIZE];

int hash (long long id){
    return abs(id) % HASH_SIZE;
}

Item * findItem (long long id){
    int index = hash(id);
    Item* current = hashtable[index].head;
    while (current != NULL){
        if (current->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addItem(long long id, long long quantity) {
    int index = hash(id);
    Item* current = hashtable[index].head;
    while (current != NULL) {
        if (current->id == id) {
            current->quantity += quantity;
            return;
        }
        current = current->next;
    }
    Item* newItem = (Item*) malloc(sizeof(Item));
    newItem->id = id;
    newItem->quantity = quantity;
    newItem->next = hashtable[index].head;
    hashtable[index].head = newItem;
}

void removeItem(long long id, long long quantity) {
    int index = hash(id);
    Item* current = hashtable[index].head;
    Item* prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            current->quantity -= quantity;
            if (current->quantity <= 0) {
                if (prev == NULL) {
                    hashtable[index].head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

long long countItems() {
    long long count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Item* current = hashtable[i].head;
        while (current != NULL) {
            count += current->quantity;
            current = current->next;
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long K, Q;
        scanf("%lld %lld", &K, &Q);
        if (Q > 0) {
            addItem(K, Q);
        } else {
            removeItem(K, -Q);
        }
    }
    printf("%lld\n", countItems());
    return 0;
}