// game
#include <iostream>

using namespace std;

int m, n;

int main() {
    while (cin >> m) {
        for (int i = 0; i < m; ++i) {
            cin >> n;
            if (n) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}

