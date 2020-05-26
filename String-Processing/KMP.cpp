#include <bits/stdc++.h>
using namespace std;

int pre[123456];
void PrefixTable(string &p) {
    int m = p.size();
    pre[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j && p[j] != p[i]) j = pre[j - 1];
        if (p[j] == p[i]) j++;
        pre[i] = j;
    }
}

bool kmp(string &s, string &p) {
    PrefixTable(p);
    int n = s.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == p[j]) {
            j++;
            if (j == m) return true;
        } else {
            int k = j ? i - 1 : i;
            while (j && s[i] != p[j]) j = pre[j - 1];
            i = k;
        }
        i++;
    }
    return false;
}

int main() {
    string str, pat;
    getline(cin, str);
    getline(cin, pat);
    cout << kmp(str, pat);
    return 0;
}
