#include <bits/stdc++.h>

using namespace std;

struct Li_Chao {
    /**
     *    add lines of the form y = mx + c, and calculate maximum value at points x
     *    to calculate minimum value at point x, add Line(-m, -c). The answer is -f(x)
    **/

    struct Line {
        long long m, c;
        long long operator() (long long x) {
            return m * x + c;
        }
    };

    struct Node {
        Line line;
        Node *left, *right;
        Node(Line line): line(line), left(0), right(0) {}
    } *root;

    Li_Chao() {
        root = new Node({0, LLONG_MIN});
    }

    void add(Node* node, int l, int r, Line line) {
        if (l + 1 == r) {
            if (line(l) > node->line(l)) {
                node->line = line;
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (line.m < node->line.m) {
            swap(line, node->line);
        }
        if (node->line(mid) > line(mid)) {
            if (node->right) {
                add(node->right, mid, r, line);
            } else {
                node->right = new Node(line);
            }
        } else {
            swap(line, node->line);
            if (node->left) {
                add(node->left, l, mid, line);
            } else {
                node->left = new Node(line);
            }
        }
    }

    long long ask(Node* node, int l, int r, int x) {
        if (l + 1 == r) {
            return node->line(x);
        }
        int mid = (l + r) >> 1;
        if (x < mid && node->left) {
            return max(node->line(x), ask(node->left, l, mid, x));
        } else if (node->right) {
            return max(node->line(x), ask(node->right, mid, r, x));
        } else {
            return node->line(x);
        }
    }
};

int main() {

    return 0;
}