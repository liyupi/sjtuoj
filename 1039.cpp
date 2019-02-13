// 二叉树左孩子下标等于父节点下标 * 2，右孩子再+1
#include <iostream>

using namespace std;

int N;

struct Node {
    int leftChild;
    int rightChild;
    int index;
    int val;
};

void preOrder(Node root, Node nodes[]) {
    if (root.leftChild != -1) {
        nodes[root.leftChild].index = 2 * root.index;
        preOrder(nodes[root.leftChild], nodes);
    }
    if (root.rightChild != -1) {
        nodes[root.rightChild].index = 2 * root.index + 1;
        preOrder(nodes[root.rightChild], nodes);
    }
}

void postOrder(Node root, Node nodes[]) {
    if (root.leftChild != -1) {
        postOrder(nodes[root.leftChild], nodes);
    }
    if (root.rightChild != -1) {
        postOrder(nodes[root.rightChild], nodes);
    }
    cout << root.val << " ";
}

int main() {
    while (cin >> N) {
        Node nodes[N + 1];
        nodes[1].index = 1;
        for (int i = 1; i <= N; ++i) {
            int x;
            cin >> x;
            cin >> nodes[x].leftChild >> nodes[x].rightChild;
            nodes[x].val = x;
        }
        preOrder(nodes[1], nodes);
        for (int i = 1; i < N; ++i) {
            cout << nodes[i].index << " ";
        }
        cout << nodes[N].index << endl;
        postOrder(nodes[1], nodes);
    }
    return 0;
}