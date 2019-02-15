#include <iostream>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        int dp[N + 1];
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i] = dp[i - 1] + 2 * ((i - 1) / 2 + 1);
        }
        cout << dp[N] << endl;
    }
    return 0;
}
