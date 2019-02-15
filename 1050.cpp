// 做法1：左倾堆
// 做法2：优先队列，通过弹出值实现合并
// 你敢想？左倾堆竟然超时
#include <iostream>
#include <queue>

using namespace std;

int N, M;

// 做法1
/* struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    int npl = -1;
    int val = 0;
};

void swapNode(Node *&root1, Node *&root2) {
    Node *tmp = root1;
    root1 = root2;
    root2 = tmp;
}

// 合并堆
Node *merge(Node *root1, Node *root2) {
    if (root1 == nullptr) {
        return root2;
    }
    if (root2 == nullptr) {
        return root1;
    }
    if (root1->val > root2->val) {
        swapNode(root1, root2);
    }
    root1->right = merge(root1->right, root2);
    if (root1->left == nullptr || root1->left->npl < root1->right->npl) {
        swapNode(root1->left, root1->right);
    }
    if (root1->left != nullptr && root1->right != nullptr) {
        root1->npl = root1->right->npl + 1;
    }
    return root1;
}

// 弹出最小值
Node *pop(Node *root) {
    return merge(root->left, root->right);
}

// 插入新值
Node *push(Node *root, int val) {
    Node *node = (Node *) malloc(sizeof(struct Node));
    node->val = val;
    return merge(root, node);
}

int main() {
    while (~scanf("%d%d", &N, &M)) {
        Node *groups[N];
        for (int i = 0; i < N; ++i) {
            groups[i] = (Node *) malloc(sizeof(struct Node));
            scanf("%d", &groups[i]->val);
        }
        for (int i = 0; i < M; ++i) {
            int op, a, b;
            cin >> op;
            switch (op) {
                case 0:
                    scanf("%d%d", &a, &b);
                    groups[a] = merge(groups[a], groups[b]);
                    break;
                case 1:
                    scanf("%d", &a);
                    if (groups[a] != nullptr) {
                        cout << groups[a]->val << endl;
                        groups[a] = pop(groups[a]);
                    } else {
                        cout << -1 << endl;
                    }
                    break;
                default:
                    scanf("%d%d", &a, &b);
                    groups[a] = push(groups[a], b);
            }
        }
    }
    return 0;
}*/

// 做法2

struct Group {
    priority_queue<int, vector<int>, greater<int>> pq;

    Group(int ele) {
        pq.push(ele);
    }

    void delete_min() {
        pq.pop();
    }

    void add_in(int new_one) {
        pq.push(new_one);
    }

    void merge_with(Group &another) {
        while (!another.pq.empty()) {
            this->add_in(another.pq.top());
            another.pq.pop();
        }
    }
};

int main() {
    while (cin >> N >> M) {
        vector<Group> groups;
        for (int i = 0; i < N; ++i) {
            int val;
            scanf("%d", &val);
            groups.push_back(Group(val));
        }
        for (int i = 0; i < M; ++i) {
            int op, a, b;
            scanf("%d", &op);
            switch (op) {
                case 0:
                    scanf("%d%d", &a, &b);
                    groups[a].merge_with(groups[b]);
                    break;
                case 1:
                    scanf("%d", &a);
                    if (groups[a].pq.empty())
                        printf("-1\n");
                    else {
                        printf("%d\n", groups[a].pq.top());
                        groups[a].delete_min();
                    }
                    break;
                default:
                    scanf("%d%d", &a, &b);
                    groups[a].add_in(b);
            }
        }
    }
    return 0;
}
