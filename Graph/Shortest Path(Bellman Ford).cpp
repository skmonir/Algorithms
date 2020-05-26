#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int edge_u[N], edge_v[N], cost[N], dis[N];

bool bellman_ford(int src) {
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int u = edge_u[j];
            int v = edge_v[j];
            if (dis[v] > dis[u] + cost[j]) {
                if (i == n) return false;
                dis[v] = dis[u] + cost[j];
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m; // n = node, m = edge
    for (int i = 1; i <= m; i++) {
        cin >> edge_u[i] >> edge_v[i] >> cost[i];
    }
    int src;
    cin >> src;
    if (bellman_ford(src)) {
        for (int i = 1; i <= n; i++) {
            cout << dis[i] << ' ';
        }
    } else cout << "Negative cycle found\n";
}
