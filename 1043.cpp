// 判断完全二叉树，根据性质某节点左右子树都是完全二叉树且高度差小于1
// 或者使用层次遍历，当某节点没有右孩子时接下来遍历的节点必须为叶子节点，否则就不是完全二叉树
#include <iostream>

using namespace std;

struct Node {
    int leftChild = -1;
    int rightChild = -1;
    int height = -1;
};

Node nodes[1000001];


int getHeight(int root, Node nodes[]) {
    int left = 0, right = 0;
    if (nodes[root].leftChild != -1) {
        left = getHeight(nodes[root].leftChild, nodes);
    }
    if (nodes[root].rightChild != -1) {
        right = getHeight(nodes[root].rightChild, nodes);
    }
    nodes[root].height = max(left, right) + 1;
    return nodes[root].height;
}

bool isComplete(Node &root, Node nodes[]) {
    if (root.leftChild == -1) {
        return root.rightChild == -1;
    }
    if (!isComplete(nodes[root.leftChild], nodes)) {
        return false;
    }
    if (root.rightChild == -1) {
        return nodes[root.leftChild].height == 1;
    }
    if (!isComplete(nodes[root.rightChild], nodes)) {
        return false;
    }
    return abs(nodes[root.leftChild].height - nodes[root.rightChild].height) <= 1;
}

int N;

int main() {
    cin >> N;
    for (int i = 1; i <= N - 1; ++i) {
        int tmp;
        cin >> tmp;
        if (nodes[tmp].leftChild == -1) {
            nodes[tmp].leftChild = i;
        } else {
            nodes[tmp].rightChild = i;
        }
    }
    getHeight(0, nodes);
    cout << (isComplete(nodes[0], nodes) ? "true" : "false") << endl;
    return 0;
}