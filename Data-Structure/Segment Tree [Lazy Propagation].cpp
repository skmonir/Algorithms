#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 5;

long long t[N << 2], f[N << 2];

void propagate(int nd, int s, int e) {
    if (f[nd]) {
        t[nd] += f[nd] * (e - s + 1);
        if (s != e) f[nd << 1] += f[nd], f[nd << 1 | 1] += f[nd];
        f[nd] = 0;
    }
}

void upd(int nd, int s, int e, int l, int r, long long v) {
    propagate(nd, s, e);
    if (e < l or r < s) return;
    if (s >= l and e <= r) {
        f[nd] += v;
        propagate(nd, s, e);
        return;
    }
    int md = (s + e) >> 1;
    upd(nd << 1, s, md, l, r, v);
    upd(nd << 1 | 1, md + 1, e, l, r, v);
    t[nd] = t[nd << 1] + t[nd << 1 | 1];
}

long long ask(int nd, int s, int e, int l, int r) {
    propagate(nd, s, e);
    if (e < l or r < s) return 0;
    int md = (s + e) >> 1;
    if (s >= l and e <= r) return t[nd];
    long long c1 = ask(nd << 1, s, md, l, r);
    long long c2 = ask(nd << 1 | 1, md + 1, e, l, r);
    return c1 + c2;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof f);
    memset(t, 0, sizeof t);
    while (m--) {
        int cc, l, r;
        long long v;
        scanf("%d%d%d", &cc, &l, &r);
        l++, r++;
        if (cc) printf("%lld\n", ask(1, 1, n, l, r));
        else {
            scanf("%lld", &v);
            upd(1, 1, n, l, r, v);
        }
    }
    return 0;
}
