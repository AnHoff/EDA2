#include <stdio.h>

int main() {
    int N, M, P;
    int passo, xPA = 1, yPA = 1, xPB, yPB;
    
    // Leitura das dimensões do CP e do número de passos
    scanf("%d %d", &N, &M);
    scanf("%d", &P);
    
    // Definição da posição inicial de PB
    xPB = N;
    yPB = M;
    
    // Loop para cada passo
    for (passo = 1; passo <= P; passo++) {
        int dirPA, dirPB;
        scanf("%d %d", &dirPA, &dirPB);
        
        // Movimento de PA
        if (dirPA == 1) yPA++;
        else if (dirPA == 2) yPA--;
        else if (dirPA == 3) xPA++;
        else if (dirPA == 4) xPA--;
        
        // Verificação se PA saiu do CP
        if (xPA < 1 || xPA > N || yPA < 1 || yPA > M) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", xPA, yPA, passo);
            return 0;
        }
        
        // Movimento de PB
        if (dirPB == 1) yPB++;
        else if (dirPB == 2) yPB--;
        else if (dirPB == 3) xPB++;
        else if (dirPB == 4) xPB--;
        
        // Verificação se PB saiu do CP
        if (xPB < 1 || xPB > N || yPB < 1 || yPB > M) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", xPB, yPB, passo);
            return 0;
        }
        
        // Verificação se os professores se encontraram
        if (xPA == xPB && yPA == yPB) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", xPA, yPA, passo);
            return 0;
        }
    }
    
    // Se nenhum dos casos anteriores ocorreu, os professores não se encontraram
    printf("Nao se encontraram\n");
    
    return 0;
}
