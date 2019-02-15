#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        int nums[N];
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }
        sort(nums, nums + N);
        int left = 0;
        int right = N - 1;
        int sum = 0;
        while(left < right) {
            sum += nums[right] - nums[left];
            left++;
            right--;
        }
        cout << sum << endl;
    }
    return 0;
}
