#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;


int a[N];

int seg[N * 3], lazy[N * 3];

void build(int lo, int hi, int node) {
    if (lo == hi) {
        seg[node] = a[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(lo, mid, node * 2 + 1);
    build(mid + 1, hi, node * 2 + 2);
    seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
}

void update(int lo, int hi, int left, int right, int node, int value) {
    if (lo > hi) return;
    if (lazy[node] != 0) {
        seg[node] += lazy[node];
        if (lo != hi) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (right < lo || left > hi) return;
    if (lo >= left && hi <= right) {
        seg[node] += value;
        if (lo != hi) {
            lazy[node * 2 + 1] += value;
            lazy[node * 2 + 2] += value;
        }
        return;
    }
    int mid = (lo + hi) >> 1;
    update(lo, mid, left, right, node * 2 + 1, value);
    update(mid + 1, hi, left, right, node * 2 + 2, value);
    seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
}

int query(int lo, int hi, int left, int right, int node) {
    if (lo > hi) return INT_MAX;
    if (lazy[node] != 0) {
        seg[node] += lazy[node];
        if (lo != hi) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (right < lo || left > hi) return INT_MAX;
    if (lo >= left && hi <= right) return seg[node];
    int mid = (lo + hi) >> 1;
    int a = query(lo, mid, left, right, node * 2 + 1);
    int b = query(mid + 1, hi, left, right, node * 2 + 2);
    return min(a, b);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    build(1, n, 0);
    int q; scanf("%d", &q);
    while (q--) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 2) printf("%d\n", query(1, n, x, y, 0));
        else {
            int z; scanf("%d", &z);
            update(1, n, x, y, 0, z);
        }
    }
}