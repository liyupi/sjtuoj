// nasty problem
#include<iostream>
#include<cstring>
#include <iomanip>

using namespace std;

string getSumStr(string str1, string str2, int carry);

string fillZero(string str, int len, bool left);

int main() {
    string a, b;
    while (cin >> a >> b) {
        unsigned long dPos1 = a.find('.');
        unsigned long dPos2 = b.find('.');
        string z1 = a.substr(0, dPos1);
        string z2 = b.substr(0, dPos2);
        string f1 = a.substr(dPos1 + 1);
        string f2 = b.substr(dPos2 + 1);
        int lenF1 = (int) f1.length();
        int lenF2 = (int) f2.length();
        if (lenF1 > lenF2) {
            f2 = fillZero(f2, lenF1, false);
        } else if (lenF1 < lenF2) {
            f1 = fillZero(f1, lenF2, false);
        }
        int lenZ1 = (int) z1.length();
        int lenZ2 = (int) z2.length();
        if (lenZ1 > lenZ2) {
            z2 = fillZero(z2, lenZ1, true);
        } else if (lenZ1 < lenZ2) {
            z1 = fillZero(z1, lenZ2, true);
        }
        string fSum;
        string resF = getSumStr(f1, f2, false);
        bool carry = false;
        if(resF.length() > f1.length()) {
            carry = true;
            resF = resF.substr(1);
        }
        string resZ;
        if (carry) {
            resZ = getSumStr(z1, z2, 1);
        } else {
            resZ = getSumStr(z1, z2, 0);
        }
        cout << resZ << "." << resF << endl;


    }
    return 0;
}

string getSumStr(string str1, string str2, int carry) {
    int len = (int) str1.length();
    string res;
    for (int i = len - 1; i >= 0; --i) {
        int num = str1[i] + str2[i] - 96 + carry;
        if (num > 9) {
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res = to_string(num) + res;
    }
    if (carry) {
        res = "1" + res;
    }
    return res;
}

string fillZero(string str, int len, bool left) {
    int len1 = (int) str.length();
    int diff = len - len1;
    if (left) {
        while (diff--) {
            str = '0' + str;
        }
        return str;
    } else {
        return str.append(diff, '0');
    }
}

