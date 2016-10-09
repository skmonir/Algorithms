#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e4 + 5;
int ks = 0, timer;

vector <int> g[N];
vector < pair <int, int> > ans;
int low[N], in[N], n, m;

void dfs(int cur, int par = -1) {
    low[cur] = in[cur] = ++timer;
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (to == par) continue;
        if (in[to]) low[cur] = min(low[cur], in[to]);
        else {
            dfs(to, cur);
            low[cur] = min(low[cur], low[to]);
            if (low[to] > in[cur]) {
                ans.push_back(make_pair(min(cur, to), max(cur, to)));
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!in[i]) dfs(i);
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        printf("%d - %d\n", ans[i].first, ans[i].second);
    }
}
