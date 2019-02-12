// 螺旋矩阵
// 注意方向、宽度、初始坐标
#include <iostream>
#include <iomanip>

using namespace std;

int n;
const int dirs[][2] = {{0,  1},
                       {1,  0},
                       {0,  -1},
                       {-1, 0}};

int main() {
    cin >> n;
    int map[n][n];
    int width = n;
    // 当前数值，当前坐标
    int num = 1, x = 0, y = -1;
    while (width > 0) {
        // 方向（一圈）
        for (int i = 0; i < 4; ++i) {
            if (i % 2 == 1) {
                width--;
            }
            for (int j = 0; j < width; ++j) {
                x += dirs[i][0];
                y += dirs[i][1];
                map[x][y] = num++;
            }
        }
    }
    // print
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(6) << map[i][j];
        }
        cout << endl;
    }
}