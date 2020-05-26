#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;

int n, m;
int sz[N], par[N];

struct data {
    int u, v, c;
    bool operator < (const data &x) const {
        return c < x.c;
    }
} g[N];

int root(int cur) {
    return par[cur] == cur ? cur : par[cur] = root(par[cur]);
}

void merge(int x, int y) {
    if (sz[x] > sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
}

int kruskal(int n, int m) {
    int cost = 0;
    sort(g, g + m);
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u = root(g[i].u);
        int v = root(g[i].v);
        if (u != v) cost += g[i].c, merge(u, v);
    }
    return cost;
}

int main() {
    scanf("%d%d", &n, &m); //n = node, m = edge
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].c);
    }
    kruskal(n, m);
}