#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

struct HashString {
    const int P = 131;
    const long long mod = 1e9 + 7;

    long long Hash[N], Pow[N];

    void GeneratePower() {
        Pow[0] = 1;
        for (int i = 1; i < N; i++) {
            Pow[i] = (Pow[i - 1] * P) % mod;
        }
    }

    void BuildHash(char *s) {
        for (int i = 0; s[i]; i++) {
            Hash[i] = (Hash[i - 1] + Pow[i] * s[i]) % mod;
        }
    }

    inline long long GetHash(int l, int r) {
        long long h = l ? Hash[r] - Hash[l - 1] : Hash[r];
        return (h + mod) % mod;
    }

    inline bool isMatch(int l1, int r1, int l2, int r2) {
        return (GetHash(l1, r1) * Pow[l2 - l1]) % mod == GetHash(l2, r2);
    }
} helper;

int main() {
    scanf("%s", s);
    helper.GeneratePower();
    helper.BuildHash(s);
}