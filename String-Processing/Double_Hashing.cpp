#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

const int N = 1e6 + 5;

char s[N];

struct HashString {
    ULL Hash[2][N], Pow[2][N];
    const int P[2] = {131, 151};
    void GeneratePower() {
        Pow[0][0] = Pow[1][0] = 1;
        for (int i = 1; i < N; i++) {
            Pow[0][i] = Pow[0][i - 1] * P[0];
            Pow[1][i] = Pow[1][i - 1] * P[1];
        }
    }
    void BuildHash(char *s) {
        for (int i = 0; s[i]; i++) {
            Hash[0][i] = Hash[0][i - 1] + Pow[0][i] * s[i];
            Hash[1][i] = Hash[1][i - 1] + Pow[1][i] * s[i];
        }
    }
    inline ULL GetHash(int l, int r, int f) {
        return l ? Hash[f][r] - Hash[f][l - 1] : Hash[f][r];
    }
    inline bool isMatch(int l1, int r1, int l2, int r2) {
        bool foo = GetHash(l1, r1, 0) * Pow[0][l2 - l1] == GetHash(l2, r2, 0);
        bool boo = GetHash(l1, r1, 1) * Pow[1][l2 - l1] == GetHash(l2, r2, 1);
        return foo & boo;
    }
} helper;

int main() {
    scanf("%s", s);
    helper.GeneratePower();
    helper.BuildHash(s);
}