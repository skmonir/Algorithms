#include <bits/stdc++.h>
using namespace std;
#define LL             long long
#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const int N = 1e5 + 5;
int ks = 0;


int n, m;
char s[N];
int SA[N], LCP[N];
int w[N], x[N], y[N], pos[N];

inline bool cmp(const int a, const int b, const int h) {
    return y[a] == y[b] && y[a + h] == y[b + h];
}

void Sort() {
    for (int i = 0; i < m; i++) w[i] = 0;
    for (int i = 0; i < n; i++) w[x[y[i]]]++;
    for (int i = 1; i < m; i++) w[i] += w[i - 1];
    for (int i = n - 1; i >= 0; i--) SA[--w[x[y[i]]]] = y[i];
}

void SuffixArray() {
    n++;
    for (int i = 0; i < n; i++) {
        x[i] = s[i];
        y[i] = i;
    }
    Sort();
    for (int i = 1, p = 1, h = 1; p < n; h <<= 1, m = p) {
        for (i = n - h, p = 0; i < n; i++) {
            y[p++] = i;
        }
        for (int k = 0; k < n; k++) {
            if (SA[k] >= h) {
                y[p++] = SA[k] - h;
            }
        }
        Sort();
        swap(x, y);
        x[SA[0]] = 0;
        for (i = p = 1; i < n; i++) {
            x[SA[i]] = cmp(SA[i], SA[i - 1], h) ? p - 1 : p++;
        }
    }
    for (int i = 1; i < n; i++) {
        SA[i - 1] = SA[i];
    }
    n--;
}

void kasaiLCP() {
    for (int i = 0; i < n; i++) pos[SA[i]] = i;
    for (int i = 0, h = 0; i < n; i++, h ? h-- : 0) {
        if (pos[i] > 0) {
            int j = SA[pos[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            LCP[pos[i]] = h;
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        scanf("%s", s);
        n = strlen(s);
        m = 256;
        SuffixArray();
        kasaiLCP();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i + 1 - LCP[i];
        }
        cout << ans << endl;
    }
}
