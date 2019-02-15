// 二叉树层次遍历
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    int val = 0;
};


void levelOrder(Node *root) {
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        cout << node->val << " ";
        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
    cout << endl;
}

int N;

int main() {
    while (cin >> N) {
        if (!N) {
            continue;
        }
        Node *nodes[N];
        nodes[0] = (Node *) malloc(sizeof(struct Node));
        for (int i = 1; i <= N - 1; ++i) {
            nodes[i] = (Node *) malloc(sizeof(Node));
            int parent;
            cin >> parent;
            nodes[i]->val = i;
            if (nodes[parent]->left == nullptr) {
                nodes[parent]->left = nodes[i];
            } else {
                nodes[parent]->right = nodes[i];
            }
        }
        levelOrder(nodes[0]);
    }
    return 0;
}

