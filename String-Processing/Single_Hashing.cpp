#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

const int N = 1e6 + 5;

char s[N];

struct StringHashing {
    ULL Hash[N], Pow[N];
    const int P = 131;
    void GeneratePower() {
        Pow[0] = 1;
        for (int i = 1; i < N; i++) {
            Pow[i] = Pow[i - 1] * P;
        }
    }
    void BuildHash(char *s) {
        for (int i = 0; s[i]; i++) {
            Hash[i] = Pow[i] * s[i];
            if (i) Hash[i] += Hash[i - 1];
        }
    }
    inline ULL GetHash(int l, int r) {
        return l ? Hash[r] - Hash[l - 1] : Hash[r];
    }
    inline bool isMatch(int l1, int r1, int l2, int r2) {
        return GetHash(l1, r1) * Pow[l2 - l1] == GetHash(l2, r2);
    }
} helper;

int main() {
    scanf("%s", s);
    helper.GeneratePower();
    helper.BuildHash(s);
}