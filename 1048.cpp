// 二叉树层次遍历
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    int val;
};

void levelOrder(Node *root) {
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        cout << node->val << endl;
        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
}

int n;

int main() {
    while (cin >> n) {
        Node nodes[n + 1];
        bool isRoot[n + 1];
        memset(isRoot, true, sizeof(isRoot));
        for (int i = 1; i <= n; ++i) {
            nodes[i].val = i;
        }
        int x, l, r;
        int line = (n - 1) / 2;
        for (int i = 0; i < line; ++i) {
            cin >> x >> l >> r;
            nodes[x].left = &nodes[l];
            nodes[x].right = &nodes[r];
            isRoot[l] = isRoot[r] = false;
        }
        Node *root;
        for (int i = 1; i <= n; ++i) {
            if (isRoot[i]) {
                root = &nodes[i];
                break;
            }
        }
        levelOrder(root);
    }
}
