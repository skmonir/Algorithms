#include <bits/stdc++.h>
using namespace std;

int m, n;
int g[400][400];

void warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", g[i] + j);
        }
    }
    warshall();
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d %d\n", g[x][y]);
    }
}
