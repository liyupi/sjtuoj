// 空间复杂度o(1)
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        vector<vector<int>> map;
        for (int i = 0; i < N; ++i) {
            vector<int> tmp;
            for (int j = 0; j <= i; ++j) {
                int num;
                cin >> num;
                tmp.push_back(num);
            }
            map.push_back(tmp);
        }
        int res = 0;
        for (int i = 1; i < N; ++i) {
            map[i][0] += map[i - 1][0];
            for (int j = 1; j < i; ++j) {
                map[i][j] += max(map[i - 1][j - 1], map[i - 1][j]);
            }
            map[i][i] += map[i - 1][i - 1];
        }
        for (const auto &item : map[N - 1]) {
            res = max(item, res);
        }
        cout << res << endl;
    }
    return 0;
}