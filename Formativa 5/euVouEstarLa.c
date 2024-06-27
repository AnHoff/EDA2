#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2010

int g[MAX_SIZE][MAX_SIZE];
int v[MAX_SIZE];

void solve() {
    int n, m, j;
    scanf(" %d %d %d", &n, &m, &j);
    
    for (int i = 0; i < n; i++) {
        g[i][i] = 1;
        int x;
        scanf(" %d", &x);
        for (int k = 0; k < x; k++) {
            int y;
            scanf(" %d", &y);
            g[i][y] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int x;
        scanf(" %d", &x);
        for (int y = 0; y < n; y++) {
            if (g[x][y] == 1) {
                v[y] = 2;
            }
        }
    }

    for (int i = 0; i < j; i++) {
        int x;
        scanf(" %d", &x);
        printf("%s vou estar la\n", (v[x] == 2 ? "Eu" : "Nao"));
    }
}

int main() {
    solve();
    return 0;
}
