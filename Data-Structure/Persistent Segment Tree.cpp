// Author : Sheikh Monir

#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e6 + 5;

int node, a[N], root[N], val[N], t[N][2];

int newNode(int v = 0) {
    ++node;
    val[node] = v, t[node][0] = t[node][1] = -1;
    return node;
}

void Build(int nd, int s, int e) {
    if (s == e) {
        val[nd] = a[s]; return;
    }
    int md = s + e >> 1;
    t[nd][0] = newNode(), t[nd][1] = newNode();
    Build(t[nd][0], s, md);
    Build(t[nd][1], md + 1, e);
    val[nd] = val[t[nd][0]] + val[t[nd][1]];
}

int upd(int nd, int s, int e, int p, int v) {
    if (p < s or p > e) return nd;
    if (s == e) {
        int cur = newNode(val[nd] + v);
        return cur;
    }
    int md = s + e >> 1;
    int cur = newNode(val[nd]);
    t[cur][0] = upd(t[nd][0], s, md, p, v);
    t[cur][1] = upd(t[nd][1], md + 1, e, p, v);
    val[cur] = val[t[cur][0]] + val[t[cur][1]];
    return cur;
}

int ask(int nd, int s, int e, int l, int r) {
    if (e < l or s > r) return 0;
    if (l <= s and e <= r) return val[nd];
    int md = s + e >> 1;
    return ask(t[nd][0], s, md, l, r) + ask(t[nd][1], md + 1, e, l, r);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    root[0] = newNode();
    Build(root[0], 1, n);

    int q; scanf("%d", &q);
    int u = 0;
    while (q--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 1) root[++u] = upd(root[b], 1, n, c, d);
        else printf("%d\n", ask(root[b], 1, n, c, d));
    }
    return 0;
}
