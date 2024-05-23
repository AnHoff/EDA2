#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TABLE_SIZE 65536

typedef struct Node {
    char word[17];
    int count;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];

uint32_t hash(const char *str) {
    uint32_t hash = 0;
    while (*str) {
        hash = (hash << 5) + (unsigned char)(*str++);
    }
    return hash % TABLE_SIZE;
}

Node *find_node(const char *word) {
    uint32_t index = hash(word);
    Node *current = hash_table[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insert_or_increment(const char *word) {
    uint32_t index = hash(word);
    Node *node = find_node(word);
    if (node) {
        node->count++;
    } else {
        node = malloc(sizeof(Node));
        strcpy(node->word, word);
        node->count = 1;
        node->next = hash_table[index];
        hash_table[index] = node;
    }
}

void reset_count(const char *word) {
    Node *node = find_node(word);
    if (node) {
        node->count = 0;
    }
}

void print_count(const char *word) {
    Node *node = find_node(word);
    if (node) {
        printf("%d\n", node->count);
    } else {
        printf("0\n");
    }
}

int main() {
    char command;
    char word[17];
    
    while (scanf("%d %16s", &command, word) != EOF) {
        if (command == 1) {
            insert_or_increment(word);
        } else if (command == 2) {
            print_count(word);
        } else if (command == 3) {
            reset_count(word);
        }
    }

    return 0;
}
