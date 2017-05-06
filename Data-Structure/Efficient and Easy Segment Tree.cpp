#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()

const int INF = 1e9 + 7;
const int N = 4e5 + 5;

int n, a[N], b[N];

void build() {
    for (int i = n - 1; i > 0; i--) {
        a[i] = max(a[i << 1], a[i << 1 | 1]);
        b[i] = min(b[i << 1], b[i << 1 | 1]);
    }
}

int Max(int l, int r) {
    int res = -INF; r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, a[l++]);
        if (r & 1) res = max(res, a[--r]);
    }
    return res;
}

int Min(int l, int r) {
    int res = INF; r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, b[l++]);
        if (r & 1) res = min(res, b[--r]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + n + i);
    for (int i = 0; i < n; i++) scanf("%d", b + n + i);

    build();

    return 0;
}
