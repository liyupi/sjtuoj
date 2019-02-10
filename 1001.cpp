#include <iostream>

using namespace std;

int main() {
    int mHeight, bHeight, num;
    while (cin >> mHeight >> bHeight >> num) {
        int res = 0;
        int height = mHeight + bHeight;
        int temp;
        for (int i = 0; i < num; ++i) {
            cin >> temp;
            res += height >= temp ? 1 : 0;
        }
        cout << res << endl;
    }
    return 0;
}