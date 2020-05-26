struct CHT_MAX {
    // slopes are non-increasing
    // for non-decreasing slopes, use -M in add() and -X in get()
    vector <long long> m, c;

    bool bad(int l1, int l2, int l3) {
        return 1.0 * (c[l2] - c[l1]) * (m[l1] - m[l3]) <=
               1.0 * (c[l3] - c[l1]) * (m[l1] - m[l2]);
    }

    void add(long long M, long long C) {
        m.emplace_back(M); c.emplace_back(C);
        int sz = m.size();
        while (sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
            m.erase(m.end() - 2);
            c.erase(c.end() - 2);
            sz--;
        }
    }

    long long f(int idx, long long X) {
        return m[idx] * X + c[idx];
    }

    long long get(long long X) {
        int lo = 0, hi = (int) m.size() - 1;
        while (hi - lo >= 5) {
            int mid1 = (lo + lo + hi) / 3;
            int mid2 = (lo + hi + hi) / 3;
            if (f(mid1, X) <= f(mid2, X)) {
                lo = mid1 + 1;
            } else {
                hi = mid2 - 1;
            }
        }
        long long ret = f(lo, X);
        for (int i = lo + 1; i <= hi; ++i) {
            ret = max(ret, f(i, X));
        }
        return ret;
    }
} cht;