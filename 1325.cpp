// 一元一次方程
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

string str;

bool getSymbol(char c, bool left) {
    return c == '+' == left;
}

int main() {
    while (cin >> str) {
        int times = 0;
        double sum = 0;
        bool left = true;
        char letter = -1;
        char op = '+';
        int len = str.length();
        for (int i = 0; i < len;) {
            if (str[i] == '=') {
                op = '+';
                left = false;
                i++;
                continue;
            }
            if (str[i] == '+' || str[i] == '-') {
                op = str[i++];
                continue;
            }
            if (str[i] >= 'a' && str[i] <= 'z') {
                letter = str[i];
                times += getSymbol(op, left) ? 1 : -1;
                i++;
                continue;
            }
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num *= 10;
                num += str[i] - 48;
                i++;
            }
            // letter
            if (i == len || str[i] < 'a' || str[i] > 'z') {
                sum += getSymbol(op, left) ? -num : num;
            } else {
                times += getSymbol(op, left) ? num : -num;
                letter = str[i];
                i++;
            }
        }
        cout << fixed << setprecision(3) << letter << '=' << sum / times << endl;
    }
}


