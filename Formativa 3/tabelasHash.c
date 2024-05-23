#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** hashTable, int index, int key) {
    Node* newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printHashTable(Node** hashTable, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d ->", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf(" %d ->", current->key);
            current = current->next;
        }
        printf(" \\\n");
    }
}

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);

    for (int caseNum = 0; caseNum < N; caseNum++) {
        int M, C; // Tamanho da tabela e número de chaves
        scanf("%d %d", &M, &C);

        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int index = key % M;
            insert(hashTable, index, key);
        }

        printHashTable(hashTable, M);

        for (int i = 0; i < M; i++) {
            Node* current = hashTable[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(hashTable);

        if (caseNum < N - 1) {
            printf("\n");
        }
    }

    return 0;
}
