#include <iostream>

using namespace std;

void translateX(int a);

void translateY(int a);

void translateXY(int a);

int n;
int map[601][601];

int main() {
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < a; ++j) {
                cin >> map[i][j];
            }
        }
        switch (b) {
            case 0:
                translateX(a);
                break;
            case 1:
                translateY(a);
                break;
            default:
                translateXY(a);
        }
        // print
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < a - 1; ++j) {
                cout << map[i][j] << " ";
            }
            cout << map[i][a - 1] << endl;
        }
    }
}

void translateX(int a) {
    int half = a / 2;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < half; ++j) {
            int temp = map[i][j];
            map[i][j] = map[i][a - j - 1];
            map[i][a - j - 1] = temp;
        }
    }
}

void translateY(int a) {
    int half = a / 2;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < a; ++j) {
            int temp = map[i][j];
            map[i][j] = map[a - i - 1][j];
            map[a - i - 1][j] = temp;
        }
    }
}

void translateXY(int a) {
    int half = a / 2;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = map[i][j];
            map[i][j] = map[j][i];
            map[j][i] = temp;
        }
    }
}