// quick sort
#include <iostream>

using namespace std;

int N;

void qsort(int nums[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int num = nums[left];
    int pos = left;
    for (int i = left + 1; i < right; ++i) {
        if (nums[i] < num) {
            pos++;
            swap(nums[pos], nums[i]);
        }
    }
    swap(nums[left], nums[pos]);
    qsort(nums, left, pos);
    qsort(nums, pos + 1, right);
}

int main() {
    while (cin >> N) {
        int nums[N];
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }
        qsort(nums, 0, N);
        for (int i = 0; i < N; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
}

