#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int Log = 17;
const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;


int n, m, nd;
vector <int> g[N];
int sz[N], par[N], used[N];

void GetSize(int u, int p) {
    nd++, sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p or used[v]) continue;
        GetSize(v, u), sz[u] += sz[v];
    }
}

int GetCenter(int u, int p) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p or used[v]) continue;
        if (sz[v] > nd / 2) return GetCenter(v, u);
    }
    return u;
}

void Divide(int u, int p) {
    nd = 0;
    GetSize(u, u);
    int center = GetCenter(u, u);
    par[center] = p, used[center] = 1;
    for (int i = 0; i < g[center].size(); i++) {
        int v = g[center][i];
        if (!used[v]) Divide(v, center);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Divide(1, 0);
    return 0;
}
