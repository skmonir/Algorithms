#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct UnionFind {
    int sz[N], par[N];
    void initialize(int n) {
        for (int i = 0; i <= n; i++) {
            sz[i] = 1, par[i] = i;
        }
    }
    int root(int u) {
        return par[u] == u ? u : par[u] = root(par[u]);
    }
    void merge(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[v] = u, sz[u] += sz[v];
    }
} helper;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    helper.initialize(n);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        helper.merge(u, v);
    }
    int best = 0;
    for (int i = 0; i <= n; i++) {
        best = max(best, helper.sz[i]);
    }
    printf("%d\n", best);
}
