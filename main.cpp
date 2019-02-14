// 利用对区间左右的记录来合并区间
#include <iostream>
#include <algorithm>

using namespace std;

int N;

struct Pos {
    int left;
    int right;
};

bool cmp(Pos a, Pos b) {
    return a.left < b.left;
}

int main() {
    while (cin >> N) {
        Pos pos[N];
        for (int i = 0; i < N; ++i) {
            cin >> pos[i].left >> pos[i].right;
        }
        sort(pos, pos + N, cmp);
        int res = 0;
        int left = pos[0].left;
        int right = pos[0].right;
        for (int i = 1; i < N; ++i) {
            if(pos[i].left < right) {
                right = max(right, pos[i].right);
            } else {
                res += right - left;
                left = pos[i].left;
                right = pos[i].right;
            }
        }
        cout << res + right - left << endl;
    }
}