#include <iostream>

using namespace std;

int cost[12];

int main() {
    int left = 0;
    int store = 0;
    for (int i = 0; i < 12; ++i) {
        cin >> cost[i];
        left += 300 - cost[i];
        if (left < 0) {
            cout << "-" << i + 1 << endl;
            return 0;
        }
        int tmp = left % 100;
        store += left - tmp;
        left = tmp;
    }
    cout << store * 1.2 + left << endl;
    return 0;
}