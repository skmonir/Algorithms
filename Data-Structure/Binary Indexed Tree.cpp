#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct BinaryIndexedTree {
    int BIT[N];
    void init() {
        for (int i = 0; i < N; i++) BIT[i] = 0;
    }
    void upd(int x, int d) {
        while (x < N) BIT[x] += d, x += x & -x;
    }
    int ask(int x) {
        int s = 0;
        while (x > 0) s += BIT[x], x -= x & -x;
        return s;
    }
    int ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
} fen;

int main() {
}
