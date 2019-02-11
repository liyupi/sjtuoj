#include<iostream>
#include<cstring>

using namespace std;

int n, map[9][9];

bool checkbox(int i, int j);

int main() {
    while (cin >> n) {
        while (n--) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cin >> map[i][j];
                }
            }
            bool flag = true;
            // row
            for (int i = 0; i < 9; ++i) {
                int appear[10];
                memset(appear, 0, sizeof(appear));
                for (int j = 0; j < 9; ++j) {
                    if (!appear[map[i][j]]) {
                        appear[map[i][j]] = 1;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                // col
                for (int i = 0; i < 9; ++i) {
                    int appear[10];
                    memset(appear, 0, sizeof(appear));
                    for (int j = 0; j < 9; ++j) {
                        if (!appear[map[j][i]]) {
                            appear[map[j][i]] = 1;
                        } else {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag) {
                // box
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (!checkbox(i * 3, j * 3)) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            cout << (flag ? "Right" : "Wrong") << endl;
        }
    }
}

bool checkbox(int i, int j) {
    int appear[10];
    memset(appear, 0, sizeof(appear));
    for (int k = i; k < i + 3; ++k) {
        for (int l = j; l < j + 3; ++l) {
            if (!appear[map[k][l]]) {
                appear[map[k][l]] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}