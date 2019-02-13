// 完全背包问题
// o(n^2)时间复杂度，状态转移方程：如果还能装下该物品，则最大价值为该物品价值+去除该物品体积的背包的最大价值
#include <iostream>
#include <cstring>

using namespace std;

int V, N;

int main() {
    while (cin >> V >> N) {
        // dp[i]表示重量为i时的最大价值
        int c[N], w[N], dp[V + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; ++i) {
            cin >> c[i] >> w[i];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (j >= c[i]) {
                    dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
                }
            }
        }
        cout << dp[V] << endl;
    }
    return 0;
}