#include <bits/stdc++.h>
using namespace std;
int BIT[100005];

void init(int a[], int n) {
    memset(BIT, 0, sizeof BIT);
    for (int i = 1; i <= n; i++) {
        int indx = i;
        int value = a[i];
        while (indx <= n) {
            BIT[indx] += value;
            indx += indx & -indx;
        }
    }
}
void update(int indx, int data, int n) {
    while (indx <= n) {
        BIT[indx] += data;
        indx += indx & -indx;
    }
}
int query(int indx) {
    int sum = 0;
    while (indx) {
        sum += BIT[indx];
        indx -= indx & -indx;
    }
    return sum;
}
int main() {
    int tree[15] = {0, 3, 6, 5, 7, 4, 2, 3, 1, 2, 5, 4, 9};
    init(tree, 12);
    update(3, 5, 12);
    cout << query(3);
}
