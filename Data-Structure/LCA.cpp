#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int Log = 16;

int n, m;
vector <int> g[N];
int dep[N], Par[N][Log + 5];

void dfs(int u, int p = -1) {
    Par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= Log; i++) {
        Par[u][i] = Par[Par[u][i - 1]][i - 1];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) dfs(v, u);
    }
}

int GetLCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int dis = dep[a] - dep[b];
    for (int i = Log; i >= 0; i--) {
        if (dis & (1 << i)) a = Par[a][i];
    }
    for (int i = Log; i >= 0; i--) {
        if (Par[a][i] != Par[b][i]) {
            a = Par[a][i], b = Par[b][i];
        }
    }
    return a == b ? a : Par[a][0];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
}