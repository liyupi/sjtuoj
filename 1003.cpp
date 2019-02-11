// bfs
#include<iostream>
#include<queue>

using namespace std;

const int dir[4][2] = {{1,  0},
                       {-1, 0},
                       {0,  1},
                       {0,  -1}};
int map[100][100], L;

struct Pos {
    int x;
    int y;

    Pos(int x, int y) : x(x), y(y) {}
};


int main() {
    while (cin >> L) {
        queue<Pos> queue;
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 1) {
                    queue.push(Pos(i, j));
                }
            }
        }
        int res = -1;
        while (!queue.empty()) {
            long size = queue.size();
            res++;
            while (size--) {
                Pos pos = queue.front();
                queue.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = pos.x + dir[i][0];
                    int y = pos.y + dir[i][1];
                    if (x >= 0 && y >= 0 && x < L && y < L && map[x][y] == 0) {
                        map[x][y] = 1;
                        queue.push(Pos(x, y));
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}