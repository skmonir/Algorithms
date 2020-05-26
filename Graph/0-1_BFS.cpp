#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;


int dis[N];
vector < pair <int, int> > g[N];


void bfs(int s) {
    deque <int> q;
    fill(dis, dis + N, INF);
    q.push_back(s);
    dis[s] = 0;
    while (not q.empty()) {
        int u = q.front(); q.pop_front();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int c = g[u][i].second;
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                if (c) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    int src; scanf("%d", &src);
    bfs(src);

    while (true) {
        int u; cin >> u;
        cout << dis[u] << endl;
    }
    return 0;
}

/*
9 12
1 7 0
3 6 0
6 9 0
5 9 0
8 9 0
7 4 0
1 2 1
2 6 1
3 5 1
5 4 1
7 8 1
4 8 1
1
*/