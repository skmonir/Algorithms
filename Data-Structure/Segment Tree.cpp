#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;

int a[N], seg[N * 3];

void build(int lo, int hi, int node) {
    if (lo == hi) {
        seg[node] = a[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(lo, mid, node * 2 + 1);
    build(mid + 1, hi, node * 2 + 2);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}

void update(int lo, int hi, int pos, int node, int value) {
    if (pos < lo || pos > hi) return;
    if (pos <= lo && hi <= pos) {
        seg[node] += value;
        return;
    }
    int mid = (lo + hi) >> 1;
    update(lo, mid, pos, node * 2 + 1, value);
    update(mid + 1, hi, pos, node * 2 + 2, value);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}

int query(int lo, int hi, int left, int right, int node) {
    if (left <= lo && hi <= right) return seg[node];
    if (right < lo || hi < left) return 0;
    int mid = (lo + hi) >> 1;
    int res = query(lo, mid, left, right, node * 2 + 1);
    return res = res + query(mid + 1, hi, left, right, node * 2 + 2);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    build(1, n, 0);
    while (q--) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1) update(1, n, x, 0, y);
        else printf("%d\n", query(1, n, x, y, 0));
    }
}