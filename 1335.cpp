// priority queue
#include <iostream>
#include <queue>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        priority_queue<int,vector<int>,greater<int>> queue;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            queue.push(num);
        }
        long long sum = 0;
        while(queue.size() > 1) {
            int num1 = queue.top();
            queue.pop();
            int num2 = queue.top();
            queue.pop();
            int tmp = num1 + num2;
            sum += tmp;
            queue.push(tmp);
        }
        cout << sum << endl;
    }
    return 0;
}