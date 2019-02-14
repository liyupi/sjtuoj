#include <iostream>
#include <set>

using namespace std;

int n, m;

int main() {
    set<int> set;
    while (cin >> n) {
        int num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            set.insert(num);
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> num;
            if (set.find(num) != set.end()) {
                cout << 'Y' << endl;
            } else {
                cout << 'N' << endl;
            }
        }
    }
}