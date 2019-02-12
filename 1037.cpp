// 排序后滑动
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    while (cin >> n >> m) {
        int high[n], low[m];
        for (int i = 0; i < n; ++i) {
            cin >> high[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> low[i];
        }
        sort(high, high + n);
        sort(low, low + m);
        int posH = n - 1, posL = m - 1;
        int gift = 0;
        while (posL >= 0 && posH >= 0) {
            if (high[posH] > low[posL]) {
                posH--;
                gift++;
            }
            posL--;
        }
        cout << n + gift << endl;
    }
}