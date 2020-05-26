#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define mod                 1000000007LL
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> T modinverse(T bs) {return modpow(bs, mod - 2);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 5e6 + 7;
const int inf = 1e9 + 7;
int tests = 1, CaseNo = 0;

int nd, t[N][3];

int NewNode() {
    ++nd;
    t[nd][0] = t[nd][1] = -1;
    return nd;
}

void add(int x, int curNode) {
    ROF (i, 30, 0) {
        int bit = 1 & (x >> i);
        if (t[curNode][bit] == -1) t[curNode][bit] = NewNode();
        curNode = t[curNode][bit];
        t[curNode][2]++;
    }
}

void remove(int x, int curNode) {
    ROF (i, 30, 0) {
        int bit = 1 & (x >> i), prvNode = curNode;
        curNode = t[curNode][bit];
        t[curNode][2]--;
        if (!t[curNode][2]) t[prvNode][bit] = -1;
    }
}

int ask(int curNode, int pos, int pi, int li, bool isLess) {
    if (curNode == -1) return 0;
    if (isLess) return t[curNode][2];
    if (pos < 0) return 0;

    int res = 0, pbit = 1 & (pi >> pos), lbit = 1 & (li >> pos);
    if (lbit == 1) {
        res += ask(t[curNode][pbit], pos - 1, pi, li, true);
        res += ask(t[curNode][pbit ^ 1], pos - 1, pi, li, false);
    } else {
        res += ask(t[curNode][pbit], pos - 1, pi, li, false);
    }

    return res;
}

int solve() {
    int q; Int(q);

    int root = NewNode();
    while (q--) {
        int tp, p; Int(tp, p);
        if (tp == 1) add(p, root);
        if (tp == 2) remove(p, root);
        if (tp == 3) {
            int l; Int(l);
            printf("%d\n", ask(root, 30, p, l, false));
        }
    }

    return 0;
}

int main() {
    //Int(tests);

    while (tests--) {
        //printf("Case %d: ", ++CaseNo);
        solve();
    }

    return 0;
}