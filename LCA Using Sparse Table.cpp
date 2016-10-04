#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5;

vector <int> g[N + 5];
int lev[N + 5];
int table[N][22];

void dfs(int cur, int from, int l) {
    table[cur][0] = from;
    lev[cur] = l;
    for (auto i : g[cur]) {
        if (i != from) {
            dfs(i, cur, l + 1);
        }
    }
}

void build(int n) {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                table[i][j] = table[table[i][j - 1]][j - 1];
            }
        }
    }
}

int query(int a, int b) {
    if (lev[a] < lev[b]) swap(a, b);
    int k;
    for (k = 0; (1 << k) <= lev[a]; k++);
    k--;
    for (int i = k; i >= 0; i--) {
        if (lev[a] - (1 << i) >= lev[b]) {
            a = table[a][i];
        }
    }
    if (a == b) return a;
    for (int i = k; i >= 0; i--) {
        if (table[a][i] != -1 && table[a][i] != table[b][i]) {
            a = table[a][i];
            b = table[b][i];
        }
    }
    return table[a][0];
}

int main() {

    int n, q; // 1 <= n, q <= 10^5
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(table, -1, sizeof table);
    dfs(1, -1, 0);
    build(n);

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << endl;
    }
}

/*
12 20
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
6 10
6 11
7 12
*/