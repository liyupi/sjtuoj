// 大整数加法
#include <iostream>
#include <cstring>

using namespace std;

string getSum(string longer, string shorter, int longerLen, int shorterLen) {
    string res;
    int carry = 0;
    bool zero = false;
    for (int i = 1; i <= longerLen; ++i) {
        if (!zero && i > shorterLen) {
            zero = true;
        }
        char c1 = longer[longerLen - i];
        char c2 = zero ? '0' : shorter[shorterLen - i];
        int num = c1 + c2 - 96 + carry;
        if (num >= 10) {
            carry = 1;
            num -= 10;
        } else {
            carry = 0;
        }
        res = to_string(num) + res;
    }
    if (carry) {
        return '1' + res;
    }
    return res;
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        int lenA = (int) a.length();
        int lenB = (int) b.length();
        if (lenA > lenB) {
            cout << getSum(a, b, lenA, lenB) << endl;
        } else {
            cout << getSum(b, a, lenB, lenA) << endl;
        }
    }
    return 0;
}