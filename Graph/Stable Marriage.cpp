#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 500 + 5;

int husband[N], wife[N];
int n, Rank[N][N], prefer[N][N];

void stable_marriage() {
    queue <int> q;
    for (int i = 1; i < N; i++) {
        husband[i] = wife[i] = -1;
        if (i <= n) q.push(i);
    }
    while (!q.empty()) {
        int groom = q.front(); q.pop();
        for (int i = 1; i <= n; i++) {
            int bride = prefer[groom][i];
            if (husband[bride] == -1) {
                wife[groom] = bride;
                husband[bride] = groom;
                break;
            }
            int engaged_to = husband[bride];
            if (Rank[bride][groom] < Rank[bride][engaged_to]) {
                husband[bride] = groom;
                wife[groom] = bride;
                wife[engaged_to] = -1;
                q.push(engaged_to);
                break;
            }
        }
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &prefer[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int k; scanf("%d", &k);
                Rank[i][k] = j;
            }
        }
        stable_marriage();
        for (int i = 1; i <= n; i++) {
            printf("%d %d\n", i, wife[i]);
        }
    }
}
