#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define Elemento int
#define chave(x) (x)
#define menor(a, b) (a > b)
#define trocar(a, b)  \
    {                 \
        Elemento tmp = a; \
        a = b;        \
        b = tmp;      \
    }
#define comparar_trocar(a, b) \
    if (menor(b, a))          \
    trocar(a, b)

Elemento ITEM_NULO = -1;

typedef struct
{
    Elemento *vetor;
    size_t tamanho, capacidade;
} FilaDePrioridade;

void HEAP_ajustar_para_cima(Elemento *vetor, int i)
{
    for (; i > 1 && menor(vetor[i / 2], vetor[i]); i /= 2)
        trocar(vetor[i], vetor[i / 2]);
}

void HEAP_ajustar_para_baixo(Elemento *vetor, size_t tamanho, int i)
{
    for (int maior = i * 2; i * 2 <= tamanho; i = maior, maior = i * 2)
    {
        if (maior < tamanho && menor(vetor[maior], vetor[maior + 1]))
            maior++;

        if (!menor(vetor[i], vetor[maior]))
            break;

        trocar(vetor[i], vetor[maior]);
    }
}

FilaDePrioridade FP_inicializar(size_t capacidade)
{
    FilaDePrioridade fila = {.capacidade = capacidade, .tamanho = 0};
    fila.vetor = malloc((capacidade + 1) * sizeof(Elemento));
    return fila;
}

void FP_liberar(FilaDePrioridade fila)
{
    free(fila.vetor);
}

int FP_estaVazia(FilaDePrioridade fila)
{
    return fila.tamanho == 0;
}

void FP_garantirCapacidade(FilaDePrioridade *fila, size_t novaCapacidade)
{
    if (novaCapacidade <= fila->capacidade)
        return;

    fila->capacidade *= 4;
    fila->vetor = realloc(fila->vetor, (fila->capacidade + 1) * sizeof(Elemento));
}

void FP_inserir(FilaDePrioridade *fila, Elemento x)
{
    FP_garantirCapacidade(fila, fila->tamanho + 1);
    fila->vetor[++fila->tamanho] = x;
    HEAP_ajustar_para_cima(fila->vetor, fila->tamanho);
}

Elemento FP_obterTopo(FilaDePrioridade fila)
{
    return fila.vetor[1];
}

Elemento FP_extrairTopo(FilaDePrioridade *fila)
{
    if (FP_estaVazia(*fila))
        return ITEM_NULO;

    Elemento topo = FP_obterTopo(*fila);
    fila->vetor[1] = fila->vetor[fila->tamanho--];
    HEAP_ajustar_para_baixo(fila->vetor, fila->tamanho, 1);
    return topo;
}

int main()
{
    FilaDePrioridade fila = FP_inicializar(16);
    int tipo, prioridade, vetor_aux[100];

    while (scanf(" %d %d", &tipo, &prioridade) == 2)
    {
        if (tipo == 1)
            FP_inserir(&fila, prioridade);
        else
        {
            int n;
            for (n = 0; n < prioridade; n++)
            {
                int topo = FP_extrairTopo(&fila);
                if (topo == ITEM_NULO)
                    break;
                vetor_aux[n] = topo;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d%c", vetor_aux[i], " \n"[i == n-1]);
                FP_inserir(&fila, vetor_aux[i]);
            }
        }
    }

    FP_liberar(fila);

    return 0;
}
