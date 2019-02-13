#include <iostream>
#include <cstring>

using namespace std;

int N;

int main() {
    cin >> N;
    while(N--) {
        string str;
        cin >> str;
        int num = 0;
        bool flag = true;
        int len = (int) str.length();
        for (int i = 0; i < len; ++i) {
            char c = str[i];
            if(c == '(') {
                num++;
            } else {
                if(!num) {
                    flag = false;
                    break;
                }
                num--;
            }
        }
        if (flag && !num) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}