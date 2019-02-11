// 神思路，区别于连续子序列最大和，这题要求间隔1个下标（及最大和子序列长度至少为2）
// 整体思路为：想办法丢弃掉负值，保留正值
#include<iostream>

using namespace std;

int n;

int main() {
    while (cin >> n) {
        int num[n];
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        int max = -1;
        int maxSum = num[0] + num[1];
        for (int i = 2; i < n; ++i) {
            // maxSum = num[i - 1] + num[i - 2] + ...，即前n项最大子序列的和，若大于num[i - 1]，说明前面i - 2项的和为正，可以保留
            // 否则丢弃前i - 2项
            // maxSum也可换成dp[i]数组，表示以第i个数结尾的最大子序列和
            maxSum = maxSum > num[i - 1] ? maxSum + num[i] : num[i - 1] + num[i];
            max = maxSum > max ? maxSum : max;
        }
        if (max < 0) {
            cout << "Game Over" << endl;
        } else {
            cout << max << endl;
        }
    }
}