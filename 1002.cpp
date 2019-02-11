#include<iostream>

using namespace std;
int p[1001][1001], l, w, a, b;

int main() {
    cin >> l >> w;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> p[i][j];
            // 某一位置元素值  =  正左方元素值 + 正上方元素值 - 左上角元素值
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    cin >> a >> b;
    int sum = -1;
    for (int i = a; i <= l; i++) {
        for (int j = b; j <= w; j++) {
            int t = 0;
            if (i == a) {
                t = p[i][j] - p[i][j - b];
            } else {
                t = p[i][j] - p[i][j - b] - p[i - a][j] + p[i - a][j - b];
            }
            sum = t > sum ? t : sum;
        }
    }
    cout << sum;
    return 0;
}