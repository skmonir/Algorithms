#include <bits/stdc++.h>
using namespace std;
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const int N = 1e5 + 5;

int z[N];

int z_function(string &s, int sz) {
    memset(z, 0, sizeof z);
    int R = 0, L = 0, res = 0;
    for (int k = 1; s[k]; k++) {
        if (k > R) {
            L = R = k;
            while (s[R] && s[R] == s[R - L]) R++;
            z[k] = R - L, R--;
        } else {
            int kk = k - L;
            if (k + z[kk] <= R) z[k] = z[kk];
            else {
                L = k;
                while (s[R] && s[R] == s[R - L]) R++;
                z[k] = R - L, R--;
            }
        }
    }
    for (int i = 0; s[i]; i++) {
        if (z[i] == sz) res++;
        cout << z[i] << ' ';
    } cout << endl;
    return res;
}

int main() {
    string pat, s;
    while (cin >> pat >> s) {
        string t = pat + '+' + s;
        cout << z_function(t, pat.size()) << endl;
    }
}