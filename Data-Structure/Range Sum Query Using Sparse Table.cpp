/**********************************************************************\
|                                            _                         |
|                 __   __    ____    _ __   (_)  _ __                  |
|                |  \_/  |  / __ \  | '_  \ | | | '__|                 |
|                | || || | | (__) | | | | | | | | |                    |
|                |_||_||_|  \____/  |_| |_| |_| |_|                    |
|                                                                      |
|                  Computer Science and Engineering                    |
|  Bangabandhu Sheikh Mujibur Rahman Science and Technology University |
|                                                                      |
\**********************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define F          first
#define S          second
#define pii        pair<int, int>
#define pll        pair<ll, ll>
#define mii        map<int, int>
#define mll        map<ll, ll>
#define vii        vector<int>
#define vll        vector<ll>
#define pb         push_back
#define eb         emplace_back
#define em         emplace
#define mp         make_pair
#define mt         make_tuple
#define End        return 0
#define endl       '\n'
#define inf        1e9
#define in         freopen("in.txt", "r", stdin)
#define out        freopen("out.txt", "w", stdout)
#define all(x)     x.begin(), x.end()
#define rall(x)    x.rbegin(), x.rend()
#define asort(v)   sort(v.begin(), v.end())
#define dsort(v)   sort(v.begin(), v.end(), [](int a, int b){return a > b;})
#define fill(a,b)  memset(a, b, sizeof a)
#define gcd(a,b)   __gcd(a,b)

const int N = 1e5 + 5;
const int K = 16;
ll table[N][K];
ll a[N];


void build_table(int n, int k) {
    for (int i = 0; i < n; i++) {
        table[i][0] = a[i];
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
        }
    }
}

ll query(int l, int r, int k) {
    ll ans = 0;
    for (int i = k; i >= 0; i--) {
        if (l + (1 << i) - 1 <= r) {
            ans += table[l][i];
            l += 1 << i;
        }
    }
    return ans;
}
int main() {
    int n, q, k;
    cin >> n >> q;
    for (k = 0; (1 << k) <= n; k++);
    k--;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build_table(n, k);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r, k) << endl;
    }
    End;
}
