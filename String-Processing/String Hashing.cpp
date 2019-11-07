#include <bits/stdc++.h>

using namespace std;

struct HashString {
    vector<int> P = {131, 151};
    vector<vector<long long>> Hash, Pow;
    vector<long long> Mod = {1000000007LL, 1000000009LL};

    HashString(string s) {
        Pow.clear();
        Hash.clear();
        Pow.resize(2, vector<long long> ((int) s.size()));
        Hash.resize(2, vector<long long> ((int) s.size()));

        buildHash(s);
    }

    void generatePower(int n) {
        Pow[0][0] = Pow[1][0] = 1;
        for (int i = 1; i < n; ++i) {
            Pow[0][i] = (Pow[0][i - 1] * P[0]) % Mod[0];
            Pow[1][i] = (Pow[1][i - 1] * P[1]) % Mod[1];
        }
    }

    void buildHash(string s) {
        generatePower((int) s.size());
        Hash[0][0] = Hash[1][0] = s[0];
        for (int i = 1; i < (int) s.size(); ++i) {
            Hash[0][i] = (Hash[0][i - 1] + Pow[0][i] * s[i]) % Mod[0];
            Hash[1][i] = (Hash[1][i - 1] + Pow[1][i] * s[i]) % Mod[1];
        }
    }

    long long getHash(int l, int r, int f) {
        long long h = l > 0 ? Hash[f][r] - Hash[f][l - 1] : Hash[f][r];
        return (h + Mod[f]) % Mod[f];
    }

    bool isMatch(int l1, int r1, int l2, int r2) {
        bool foo = (getHash(l1, r1, 0) * Pow[0][l2 - l1]) % Mod[0] == getHash(l2, r2, 0);
        bool boo = (getHash(l1, r1, 1) * Pow[1][l2 - l1]) % Mod[1] == getHash(l2, r2, 1);
        return foo & boo;
    }
};

int main() {
    string s; cin >> s;
    HashString helper = HashString(s);
}
