// 将一个数依次除以每个质数，并更新该数的值即可
#include <iostream>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        cout << N << "=";
        for (int i = 2; i <= N; ++i) {
            int num = 0;
            while (!(N % i)) {
                N /= i;
                num++;
            }
            if(num > 0) {
                printf("%d(%d)", i, num);
            }
        }
        cout << endl;
    }
}
