#include <iostream>

using namespace std;

int N;

int getBitNum(int num) {
    int count = 0;
    while(num) {
        num &= num - 1;
        count++;
    }
    return count;
}

int main() {
    while (cin >> N) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            sum += getBitNum(num);
        }
        cout << sum << endl;
    }
}