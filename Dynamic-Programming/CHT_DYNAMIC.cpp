#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18 + 7;

struct Line {
    mutable long long m, c, p;
    bool operator<(const Line& o) const { return m < o.m; }
    bool operator<(long long x) const { return p < x; }
};

struct HullDynamic : multiset<Line, less<>> {
    /**
     *    add lines of the form y = mx + c, and calculate maximum value at points x
     *    to calculate minimum value at point x, add Line(-m, -c). The answer is -f(x)
    **/

    long long div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b); // floored division
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf; return false;
        }
        if (x->m == y->m) {
            x->p = x->c > y->c ? inf : -inf;
        } else {
            x->p = div(y->c - x->c, x->m - y->m);
        }
        return x->p >= y->p;
    }

    void add(long long m, long long c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) {
            z = erase(z);
        }
        if (x != begin() && isect(--x, y)) {
            isect(x, y = erase(y));
        }
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }

    long long ask(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};

int main() {

    return 0;
}