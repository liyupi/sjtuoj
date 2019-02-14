// 动态约瑟夫环
// 逆推法：根据最后一轮出局的玩家编号逆推出该玩家在上一轮（直至第一轮）的编号
// 最后一轮出局的玩家编号为0（每一轮都是一个新的约瑟夫环问题）
// 公式 ans = (ans + K[M - i]) % i
#include <iostream>

using namespace std;

int M;

int main() {
    while (cin >> M) {
        int ans = 0;
        int K[M];
        for (int i = 0; i < M - 1; ++i) {
            cin >> K[i];
        }
        for (int i = 2; i <= M; ++i) {
            ans = (ans + K[M - i]) % i;
        }
        cout << ans + 1 << endl;
    }
}
