#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

int n, m, a[N];
int Max[N][25], Min[N][25];

void Build() {
    for (int i = 1; i <= n; i++) Min[i][0] = Max[i][0] = a[i];
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i - 1 + (1 << j) <= n; i++) {
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
            Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int FindMin(int l, int r) {
    int mn = INF;
    for (int i = 19; i >= 0; i--) {
        if (l - 1 + (1 << i) <= r) {
            umin(mn, Max[l][i]);
            l += (1 << i);
        }
    }
    return mn;
}

int FindMax(int l, int r) {
    int mx = 0;
    for (int i = 19; i >= 0; i--) {
        if (l - 1 + (1 << i) <= r) {
            umax(mx, Max[l][i]);
            l += (1 << i);
        }
    }
    return mx;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    Build();

    while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d %d\n", FindMin(l, r), FindMax(l, r));
    }
    return 0;
}
