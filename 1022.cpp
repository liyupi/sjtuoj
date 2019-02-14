// Fib数列对2010取余后是以2040为周期的周期数列
#include <iostream>

using namespace std;

long long N;

int main() {
    cin >> N;
    N %= 2040;
    long long pre = 0;
    long long cur = 1;
    while (--N) {
        long long tmp = cur;
        cur = (pre + cur) % 2010;
        pre = tmp;
    }
    cout << cur << endl;
}
