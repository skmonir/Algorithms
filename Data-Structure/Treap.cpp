#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;


struct Treap {
    int p, k, sz;
    long long sm;
    Treap *L, *R;
    Treap(int k, int p) : k(k), p(p), sz(0), sm(0), L(NULL), R(NULL) {}
};

typedef Treap* node;

int size(node cur) {
    return cur ? cur -> sz : 0;
}

long long sum(node cur) {
    return cur ? cur -> sm : 0;
}

void upd_sz(node cur) {
    if (cur) cur -> sz = 1 + size(cur -> L) + size(cur -> R);
}

void upd_sm(node cur) {
    if (cur) cur -> sm = cur -> k + sum(cur -> L) + sum(cur -> R);
}

void split(node cur, node &L, node &R, int k) {
    if (cur == NULL) L = R = NULL;
    else if (cur -> k > k) split(cur -> L, L, cur -> L, k), R = cur;
    else split(cur -> R, cur -> R, R, k), L = cur;
    upd_sz(cur), upd_sm(cur);
}

void insert(node &cur, node nw) {
    if (cur == NULL) cur = nw;
    else if (nw -> p > cur -> p) split(cur, nw -> L, nw -> R, nw -> k), cur = nw;
    else insert(cur -> k < nw -> k ? cur -> R : cur -> L, nw);
    upd_sz(cur), upd_sm(cur);
}

void merge(node &cur, node L, node R) {
    if (L == NULL or R == NULL) cur = L ? L : R;
    else if (L -> p > R -> p) merge(L -> R, L -> R, R), cur = L;
    else merge(R -> L, L , R -> L), cur = R;
    upd_sz(cur), upd_sm(cur);
}

void erase(node &cur, int k) {
    if (!cur) return;
    if (cur -> k == k) {
        node temp = cur;
        merge(cur, cur -> L, cur -> R);
        delete temp;
    } else erase(cur -> k < k ? cur -> R : cur -> L, k);
    upd_sz(cur), upd_sm(cur);
}

bool exist(node cur, int k) {
    if (cur == NULL) return false;
    if (cur -> k == k) return true;
    return exist(cur -> k > k ? cur -> L : cur -> R, k);
}

int Kth_num(node cur, int k) {
    if (k == size(cur -> L) + 1) return cur -> k;
    if (k <= size(cur -> L)) return Kth_num(cur -> L, k);
    else return Kth_num(cur -> R, k - size(cur -> L) - 1);
}

long long Kth_sum(node cur, int k) {
    if (!cur) return 0;
    if (k == size(cur -> L) + 1) return cur -> k + sum(cur -> L);
    if (k <= size(cur -> L)) return Kth_sum(cur -> L, k);
    else return cur -> k + sum(cur -> L) + Kth_sum(cur -> R, k - size(cur -> L) - 1);
}

int LessThanK(node cur, int k) {
    if (cur == NULL) return 0;
    int add = k > cur -> k;
    if (k >= cur -> k) return add + size(cur -> L) + LessThanK(cur -> R, k);
    return LessThanK(cur -> L, k);
}

int main() {
    node root = NULL;
    insert(root, new Treap(1, rand()));
    return 0;
}