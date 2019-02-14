#include <iostream>
#include <set>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        set<int> set;
        int n = N;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            if (set.find(num) != set.end()) {
                n--;
            } else {
                set.insert(num);
            }
        }
        cout << n << endl;
    }
}

