#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 11
#define TABLE_SIZE (1 << 20)

typedef struct FoodNode {
    char food[MAX_WORD_LENGTH];
    struct FoodNode *next;
} FoodNode;

typedef struct Colony {
    int id;
    FoodNode *foodList;
    struct Colony *next;
} Colony;

Colony *hashTable[TABLE_SIZE];

unsigned int hashFunction(int id) {
    return id % TABLE_SIZE;
}

Colony *findColony(int id) {
    unsigned int index = hashFunction(id);
    Colony *current = hashTable[index];
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertFood(Colony *colony, const char *food) {
    FoodNode *newNode = malloc(sizeof(FoodNode));
    strcpy(newNode->food, food);
    newNode->next = colony->foodList;
    colony->foodList = newNode;
}

int checkFood(Colony *colony, const char *food) {
    FoodNode *current = colony->foodList;
    while (current != NULL) {
        if (strcmp(current->food, food) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void addColony(int id, const char *food) {
    unsigned int index = hashFunction(id);
    Colony *newColony = malloc(sizeof(Colony));
    newColony->id = id;
    newColony->foodList = NULL;
    newColony->next = hashTable[index];
    hashTable[index] = newColony;
    insertFood(newColony, food);
}

int main() {
    int id;
    char food[MAX_WORD_LENGTH];

    while (scanf("%d %10s", &id, food) != EOF) {
        Colony *colony = findColony(id);
        if (colony == NULL) {
            addColony(id, food);
        } else {
            if (checkFood(colony, food)) {
                printf("%d\n", id);
            } else {
                insertFood(colony, food);
            }
        }
    }

    return 0;
}
