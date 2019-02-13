// 左孩子右兄弟树
// 遍历方式类似普通的二叉树，递归即可
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int leftChild;
    int rightBro;
    int val;
};

int n;

void postOrder(Node *root, Node nodes[]) {
    if (root->leftChild) {
        postOrder(&nodes[root->leftChild], nodes);
    }
    cout << root->val << " ";
    if (root->rightBro) {
        postOrder(&nodes[root->rightBro], nodes);
    }
}

void levelOrder(Node *root, Node nodes[]) {
    queue<Node> queue;
    queue.push(*root);
    while (!queue.empty()) {
        int size = (int) queue.size();
        for (int i = 0; i < size; ++i) {
            Node node = queue.front();
            queue.pop();
            cout << node.val << " ";
            if (node.leftChild) {
                queue.push(nodes[node.leftChild]);
                Node tmp = nodes[node.leftChild];
                while(tmp.rightBro) {
                    queue.push(nodes[tmp.rightBro]);
                    tmp = nodes[tmp.rightBro];
                }
            }
        }
    }
}

void preOrder(Node *root, Node nodes[]) {
    cout << root->val << " ";
    if (root->leftChild) {
        preOrder(&nodes[root->leftChild], nodes);
    }
    if (root->rightBro) {
        preOrder(&nodes[root->rightBro], nodes);
    }
}

int main() {
    while (cin >> n) {
        Node nodes[n + 1];
        bool isRoot[n + 1];
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cin >> nodes[x].leftChild >> nodes[x].rightBro;
            nodes[x].val = x;
            isRoot[nodes[x].leftChild] = true;
            isRoot[nodes[x].rightBro] = true;
        }
        Node *root;
        for (int i = 1; i < n + 1; ++i) {
            if (!isRoot[i]) {
                root = &nodes[i];
                break;
            }
        }
        preOrder(root, nodes);
        cout << endl;
        postOrder(root, nodes);
        cout << endl;
        levelOrder(root, nodes);
        cout << endl;
    }
}