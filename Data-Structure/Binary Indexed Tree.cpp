#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct BinaryIndexedTree {
    int BIT[N];
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
    int tree[15] = {0, 3, 6, 5, 7, 4, 2, 3, 1, 2, 5, 4, 9};
    for (int i = 1; i < 13; i++) fen.upd(i, tree[i]);
    while (true) {
        int l, r;
        cin >> l >> r;
        cout << fen.ask(l, r) << endl;
    }
}
