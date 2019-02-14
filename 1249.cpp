// 给double排序，注意两个整数相除会丢失精度
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int mother;
    int son;

    Node(int mother, int son) : mother(mother), son(son) {}
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool cmp(Node a, Node b) {
    return (double)a.son / a.mother - (double)b.son / b.mother < 0;
}

int N;

int main() {
    while (cin >> N) {
        vector<Node> list;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (gcd(i, j) == 1) {
                    list.push_back(Node(i, j));
                }
            }
        }
        sort(list.begin(), list.end(), cmp);
        for (auto &it : list) {
            cout << it.son << '/' << it.mother << endl;
        }
    }
}


