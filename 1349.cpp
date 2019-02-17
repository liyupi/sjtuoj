// dfs
#include <iostream>

using namespace std;

int R, C;

char map[16][16];

int dfs(int x, int y) {
    if (x == 0 && y == 0) {
        return 1;
    }
    int sum = 0;
    for (int i = x - 1; i >= 0; i--) {
        for (int j = y - 1; j >= 0; j--) {
            if (map[x][y] != map[i][j]) {
                sum += dfs(i, j);
            }
        }
    }
    return sum;
}

int main() {
    while (cin >> R >> C) {
        for (int i = 0; i < R; ++i) {
            cin >> map[i];
        }
        cout << dfs(R - 1, C - 1) << endl;
    }
}


