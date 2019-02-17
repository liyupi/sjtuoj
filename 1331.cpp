// 进制转换
#include <iostream>
#include <cstring>

using namespace std;

int N;

string getBase(int i, int base) {
    string res;
    while (i != 0) {
        char left = i % base + 48;
        i /= base;
        if (left > '9') {
            left += 7;
        }
        res.insert(0, 1, left);
    }
    return res;
}

bool isPalindrome(string str) {
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    while (cin >> N) {
        for (int i = 1; i <= 300; ++i) {
            string str = getBase(i * i, N);
            if (isPalindrome(str)) {
                cout << getBase(i, N) << " " << str << endl;
            }
        }
    }
    return 0;
}