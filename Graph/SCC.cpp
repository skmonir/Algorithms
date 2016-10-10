#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;


stack <int> stk;
vector <int> g[N];
int scc, timer;
int enter[N], low[N], SCC[N];

void Tarjan(int u) {
    stk.push(u);
    low[u] = enter[u] = ++timer;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (SCC[v]) continue;
        if (enter[v]) low[u] = min(low[u], enter[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == enter[u]) {
        int v; scc++;
        do {
            v = stk.top(); stk.pop();
            SCC[v] = scc;
        } while (u != v);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!enter[i]) Tarjan(i);
    }
}
