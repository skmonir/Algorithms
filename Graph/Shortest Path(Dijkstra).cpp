#include <bits/stdc++.h>
using namespace std;
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const int N = 1e5 + 5;

LL dis[N];
int used[N], par[N];
vector < pair <int, LL> > g[N];

void SPFA(int s) {
    priority_queue < pair <LL, int> > pq;
    for (int i = 0; i < N; i++) {
        dis[i] = LLONG_MAX, used[i] = 0, par[i] = -1;
    }
    dis[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        used[u] = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            LL cost = g[u][i].second;
            if (dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                par[v] = u;
                if (!used[v]) pq.push(make_pair(-dis[v], v));
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) g[i].clear();
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++) {
        LL z; scanf("%d%d%lld", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    SPFA(1);
}