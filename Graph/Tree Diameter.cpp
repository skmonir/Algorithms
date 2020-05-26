#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

vector <int> g[N];
int diam[N], h[N];

void dfs(int u, int p) {
    h[u] = 0;
    vector <int> vec;

    FOR (i, 1, g[u].size()) {
        int v = g[u][i - 1];
        if (v == p) continue;

        dfs(v, u);

        umax(h[u], h[v] + 1);
        vec.push_back(h[v] + 1);

        umax(diam[u], diam[v]);
    }
    umax(diam[u], h[u]);

    sort(rall(vec));

    if (vec.size() > 1) {
        umax(diam[u], vec[0] + vec[1]);
    }
}

int main() {

    return 0;
}