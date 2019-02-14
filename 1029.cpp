// map和vector应用
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int N;

void printBook(string books[], map<int, vector<int>> map, int head) {
    cout << books[head] << " ";
    if (map.find(head) != map.end()) {
        for (const auto &item : map[head]) {
            printBook(books, map, item);
        }
    }
}

int main() {
    while (cin >> N) {
        getchar();
        string books[N + 1];
        for (int i = 1; i <= N; ++i) {
            getline(cin, books[i]);
        }
        map<int, vector<int>> map;
        // 最前面的书
        bool isHead[N + 1];
        memset(isHead, true, sizeof(isHead));
        for (int i = 1; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            isHead[a] = false;
            if (map.find(b) != map.end()) {
                map[b].push_back(a);
            } else {
                vector<int> list;
                list.push_back(a);
                map[b] = list;
            }
        }
        int head = 1;
        for (int i = 1; i <= N; ++i) {
            if (isHead[i]) {
                head = i;
                break;
            }
        }
        printBook(books, map, head);
        cout << endl;
    }
}
