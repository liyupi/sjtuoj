#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

bool isPrime(int num) {
    int max = sqrt(num);
    for (int i = 2; i <= max; ++i) {
        if (!(num % i)) {
            return false;
        }
    }
    return true;
}

int main() {
    while (cin >> N) {
        vector<int> list = {2, 3, 5, 7};
        vector<int> next;
        int nums[] = {1, 3, 5, 7, 9};
        for (int i = 2; i <= N; ++i) {
            for (const auto &item : list) {
                for (int j = 0; j < 5; ++j) {
                    int num = 10 * item + nums[j];
                    if (isPrime(num)) {
                        next.push_back(num);
                    }
                }
            }
            list = next;
            next.clear();
        }
        for (const auto &item : list) {
            cout << item << endl;
        }
    }
    return 0;
}