// 单链表选择排序（递归）
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    Node *next;
    int val;
};

int N;

Node *selectSort(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *tmp = head;
    int minVal = tmp->val;
    Node *minPos = tmp;
    bool flag = false;
    while (tmp->next != nullptr) {
        if (tmp->next->val < minVal) {
            minVal = tmp->next->val;
            minPos = tmp;
            flag = true;
        }
        tmp = tmp->next;
    }
    if(flag) {
        tmp->next = head;
        head = minPos->next;
        minPos->next = nullptr;
    }

    head->next = selectSort(head->next);
    return head;
}

int main() {
    while (cin >> N) {
        Node *head, *pos;
        bool first = true;
        for (int i = 0; i < N; ++i) {
            Node *tmp = (Node *) malloc(sizeof(Node));
            cin >> tmp->val;
            if (first) {
                head = tmp;
                pos = head;
                first = false;
            } else {
                pos->next = tmp;
                pos = tmp;
            }
        }
        pos = selectSort(head);
        while (pos != nullptr) {
            cout << pos->val << " ";
            pos = pos->next;
        }
        cout << endl;
    }
}