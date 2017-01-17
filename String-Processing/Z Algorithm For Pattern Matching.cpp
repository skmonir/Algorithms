#include <bits/stdc++.h>
using namespace std;
#define LL             long long
#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const int N = 1e5 + 5;

int z[N];

int z_algo(string &s, int sz) {
    fill(z, 0);
    int right = 0, left = 0;
    for (int k = 1; s[k]; k++) {
        if (k > right) {
            left = right = k;
            while (s[right] && s[right] == s[right - left]) right++;
            z[k] = right - left, right--;
        } else {
            int kk = k - left;
            if (k + z[kk] <= right) z[k] = z[kk];    
            else {
                left = k;
                while (s[right] && s[right] == s[right - left]) right++;
                z[k] = right - left, right--;
            }
        }
    }
    int res = 0;
    for (int i = 0; s[i]; i++) {
        if (z[i] == sz) res++;
    }
    return res;
}

int main() {
    string pat, s;
    while (cin >> pat >> s) {
        string t = pat + '+' + s;
        cout << z_algo(t, pat.size()) << endl;
    }
}
