#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

vector <int> g[N];
int id, chain;
int a[N], pos[N], par[N], sub[N], heavy[N], head[N], belong[N];

void dfsHeavy(int u) {
    sub[u] = 1, heavy[u] = -1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == par[u]) continue;
        par[v] = u;
        dfsHeavy(v);
        if (heavy[u] == -1 or sub[v] > sub[heavy[u]]) heavy[u] = v;
        sub[u] += sub[v];
    }
}

void dfsLight(int u) {
    if (head[chain] == -1) head[chain] = u;
    belong[u] = chain;
    pos[u] = ++id;
    a[id] = u;

    if (~heavy[u]) dfsLight(heavy[u]);

    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == heavy[u] or v == par[u]) continue;
        chain++; dfsLight(v);
    }
}

void HLD(int root) {
    for (int i = 0; i < N; i++) {
        par[i] = head[i] = -1;
    }
    chain = id = 0;
    dfsHeavy(root), dfsLight(root);
}

void query_up(int u, int v) {
    int uchain, vchain;
    while (true) {
        uchain = belong[u], vchain = belong[v];
        if (uchain == vchain) {
            // modify(1, 1, n, pos[v], pos[u], val);
            break;
        }
        // modify(1, 1, n, pos[head[uchain]], pos[u], val);
        u = par[head[uchain]][0];
    }
}


int main() {
    return 0;
}