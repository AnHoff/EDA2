#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 262144  // Tamanho da tabela hash (2^18)

typedef struct Item {
    int id;
    int quantity;
    struct Item* next;
} Item;

typedef struct {
    Item** table;
} HashTable;

HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->table = (Item**)malloc(TABLE_SIZE * sizeof(Item*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

unsigned int hash(int key) {
    return (unsigned int)(key >= 0 ? key : -key) % TABLE_SIZE;
}

Item* findItem(HashTable* hashTable, int id) {
    unsigned int index = hash(id);
    Item* current = hashTable->table[index];
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    return current;
}

void addItem(HashTable* hashTable, int id, int quantity, int* totalItems) {
    unsigned int index = hash(id);
    Item* current = hashTable->table[index];
    Item* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (quantity > 0) {
            current->quantity += quantity;
            *totalItems += quantity;
        } else {
            int newQuantity = current->quantity + quantity;
            if (newQuantity <= 0) {
                *totalItems -= current->quantity;
                current->quantity = 0;
            } else {
                current->quantity = newQuantity;
                *totalItems += quantity;
            }
        }
    } else if (quantity > 0) {
        Item* newItem = (Item*)malloc(sizeof(Item));
        newItem->id = id;
        newItem->quantity = quantity;
        newItem->next = hashTable->table[index];
        hashTable->table[index] = newItem;
        *totalItems += quantity;
    }
}

void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Item* current = hashTable->table[i];
        while (current != NULL) {
            Item* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    int N;  // Número de itens
    scanf("%d", &N);

    HashTable* hashTable = createHashTable();
    int totalItems = 0;

    for (int i = 0; i < N; i++) {
        int id, quantity;
        scanf("%d %d", &id, &quantity);

        addItem(hashTable, id, quantity, &totalItems);
    }

    printf("%d\n", totalItems);

    freeHashTable(hashTable);

    return 0;
}
