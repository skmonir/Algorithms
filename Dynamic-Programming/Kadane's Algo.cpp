#include <bits/stdc++.h>

#define LL	long long

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    LL mn = 0, s = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        mn = min(mn, s);
        res = max(res, s - mn);
    }

    printf("%d\n", res);
}
