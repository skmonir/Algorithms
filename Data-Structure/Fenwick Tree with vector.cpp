#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int sz[N];
vector <int> fen[N];

void modify(int i, int j, int v) {
    while (j <= sz[i]) fen[i][j] += v, j += j & -j;
}

int ask(int i, int j) {
    int res = 0;
    while (j > 0) res += fen[i][j], j -= j & -j;
    return res;
}

int main() {
    return 0;
}