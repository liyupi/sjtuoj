// 方案数有限，可以直接暴力枚举所有方案
#include <iostream>

using namespace std;

int clocks[10];
// 每种方案旋转次数
int rot[10];
// 记录每种方案旋转结果
int path[10];

int main() {
    for (int i = 1; i <= 9; ++i) {
        cin >> clocks[i];
    }
    for (rot[1] = 0; rot[1] < 4; ++rot[1]) {
        for (rot[2] = 0; rot[2] < 4; ++rot[2]) {
            for (rot[3] = 0; rot[3] < 4; ++rot[3]) {
                for (rot[4] = 0; rot[4] < 4; ++rot[4]) {
                    for (rot[5] = 0; rot[5] < 4; ++rot[5]) {
                        for (rot[6] = 0; rot[6] < 4; ++rot[6]) {
                            for (rot[7] = 0; rot[7] < 4; ++rot[7]) {
                                for (rot[8] = 0; rot[8] < 4; ++rot[8]) {
                                    for (rot[9] = 0; rot[9] < 4; ++rot[9]) {
                                        path[1] = (clocks[1] + 3 * (rot[1] + rot[2] + rot[4])) % 12;
                                        path[2] = (clocks[2] + 3 * (rot[1] + rot[2] + rot[3] + rot[5])) % 12;
                                        path[3] = (clocks[3] + 3 * (rot[2] + rot[3] + rot[6])) % 12;
                                        path[4] = (clocks[4] + 3 * (rot[1] + rot[4] + rot[5] + rot[7])) % 12;
                                        path[5] = (clocks[5] + 3 * (rot[1] + rot[3] + rot[5] + rot[7] + rot[9])) % 12;
                                        path[6] = (clocks[6] + 3 * (rot[3] + rot[5] + rot[6] + rot[9])) % 12;
                                        path[7] = (clocks[7] + 3 * (rot[4] + rot[7] + rot[8])) % 12;
                                        path[8] = (clocks[8] + 3 * (rot[5] + rot[7] + rot[8] + rot[9])) % 12;
                                        path[9] = (clocks[9] + 3 * (rot[6] + rot[8] + rot[9])) % 12;
                                        int sum = 0;
                                        for (int i = 1; i <= 9; ++i) {
                                            sum += path[i];
                                        }
                                        if (!sum) {
                                            for (int i = 1; i <= 9; ++i) {
                                                while (rot[i]--) {
                                                    cout << i << " ";
                                                }
                                            }
                                            cout << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


