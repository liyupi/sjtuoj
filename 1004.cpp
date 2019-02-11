// easy math
#include<iostream>

using namespace std;

int M, T, U, F, D;

int main() {
    while (cin >> M >> T >> U >> F >> D) {
        int dis1 = U + D;
        int dis2 = F + F;
        int res = 0;
        int time = 0;
        for (int i = 0; i < T; ++i) {
            char tmp;
            cin >> tmp;
            if (tmp == 'u' || tmp == 'd') {
                time += dis1;
            } else {
                time += dis2;
            }
            if (time > M) {
                break;
            }
            res++;
        }
        cout << res << endl;
    }
}