#include <bits/stdc++.h>

using namespace std;

#define all(x)  x.begin(), x.end()

const int N = 2e5 + 7;

int a[N];
vector <int> t[N << 2];

void build(int nd, int s, int e) {
    if (s == e) {
        t[nd].push_back(a[s]);
        return;
    }
    int md = s + e >> 1;
    build(nd << 1, s, md);
    build(nd << 1 | 1, md + 1, e);

    t[nd].resize(t[nd << 1].size() + t[nd << 1 | 1].size());
    merge(all(t[nd << 1]), all(t[nd << 1 | 1]), t[nd].begin());
}

int ask(int nd, int s, int e, int l, int r, int k) {
    if (e < l or s > r) return 0;
    if (s >= l and e <= r) {
        int x = upper_bound(all(t[nd]), N) - t[nd].begin();
        int y = lower_bound(all(t[nd]), k) - t[nd].begin();
        return x - y;
    }
    int md = (s + e) >> 1;
    int c1 = ask(nd << 1, s, md, l, r, k);
    int c2 = ask(nd << 1 | 1, md + 1, e, l, r, k);
    return c1 + c2;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    return 0;
}