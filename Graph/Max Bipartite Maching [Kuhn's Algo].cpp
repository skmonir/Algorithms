struct KuhnImplementation {
    vector <int> g[N];
    int n, k, t, used[N], pairA[N], pairB[N];

    void init(int nn, int kk) {
        n = nn, k = kk;
        for (int i = 0; i < N; ++i) {
            g[i].clear();
            pairA[i] = pairB[i] = -1;
        }
    }

    bool Kuhn(int u) {
        if (used[u] == t) return false;

        used[u] = t;

        for (int i = 0; i < g[u].size(); ++i) {
            if (pairB[g[u][i]] == -1) {
                pairB[g[u][i]] = u;
                return true;
            }
        }

        for (int i = 0; i < g[u].size(); ++i) {
            if (Kuhn(pairB[g[u][i]])) {
                pairA[u] = g[u][i];
                pairB[g[u][i]] = u;
                return true;
            }
        }

        return false;
    }

    void FindMaxMatching() {
        bool matchFound = true;
        while (matchFound) {
            ++t, matchFound = false;
            for (int i = 1; i <= n; ++i) {
                if (pairA[i] < 0 and used[i] != t) {
                    matchFound |= Kuhn(i);
                }
            }
        }
    }
};