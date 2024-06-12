#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA (1 << 20)  // 2^20

typedef struct EntradaHash {
    long long int idColonia;
    char alimento[11];
    struct EntradaHash* proxima;
} EntradaHash;

EntradaHash* tabelaHash[TAMANHO_TABELA];

unsigned int funcaoHash(long long int idColonia, const char* alimento) {
    unsigned int hash = idColonia;
    while (*alimento) {
        hash = (hash * 31) + *alimento++;
    }
    return hash % TAMANHO_TABELA;
}

void inserir(long long int idColonia, const char* alimento) {
    unsigned int indice = funcaoHash(idColonia, alimento);
    EntradaHash* novaEntrada = (EntradaHash*)malloc(sizeof(EntradaHash));
    novaEntrada->idColonia = idColonia;
    strcpy(novaEntrada->alimento, alimento);
    novaEntrada->proxima = tabelaHash[indice];
    tabelaHash[indice] = novaEntrada;
}

int buscar(long long int idColonia, const char* alimento) {
    unsigned int indice = funcaoHash(idColonia, alimento);
    EntradaHash* entrada = tabelaHash[indice];
    while (entrada != NULL) {
        if (entrada->idColonia == idColonia && strcmp(entrada->alimento, alimento) == 0) {
            return 1;
        }
        entrada = entrada->proxima;
    }
    return 0;
}

int main() {
    long long int idColonia;
    char alimento[11];

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i] = NULL;
    }

    while (scanf("%lld %10s", &idColonia, alimento) != EOF) {
        if (buscar(idColonia, alimento)) {
            printf("%lld\n", idColonia);
        } else {
            inserir(idColonia, alimento);
        }
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        EntradaHash* entrada = tabelaHash[i];
        while (entrada != NULL) {
            EntradaHash* temp = entrada;
            entrada = entrada->proxima;
            free(temp);
        }
    }
    
    return 0;
}
