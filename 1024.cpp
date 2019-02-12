// c++ sort
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    while(cin >> n) {
        int num[n];
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        sort(num, num + n);
        for (int j = 0; j < n - 1; ++j) {
            cout << num[j] << " ";
        }
        cout << num[n - 1] << endl;
    }
}