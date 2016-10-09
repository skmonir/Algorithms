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
int table[N][K];
int a[N];

void build_table(int n, int k) {
    for(int i = 0; i < n; i++) {
        table[i][0] = a[i];
    }

    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++) {
            table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll solve(int n, int k) {
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int r = i;
        int g = 0;

        for(int j = k; j >= 0; j--) {
            if(r + (1 << j) - 1 >= n) {
                continue;
            }

            if(gcd(g, table[r][j]) > 1) {
                g = gcd(g, table[r][j]);
                r += 1 << j;
            }
        }

        ans += n - r;
    }

    return ans;
}
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, k;

    cin >> n;

    for(int i = 0; ; i++) {
        if((1 << i) > n) {
            k = i - 1;
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build_table(n, k);

    cout << solve(n, k);
    End;
}
