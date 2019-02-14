#include <iostream>
#include <iomanip>

using namespace std;

int N;

int main() {
    while (cin >> N) {
        double gpa = 0;
        for (int i = 0; i < N; ++i) {
            int score;
            cin >> score;
            if (score >= 95) {
                gpa += 4.3;
            } else if (score >= 90) {
                gpa += 4.0;
            } else if (score >= 85) {
                gpa += 3.7;
            } else if (score >= 80) {
                gpa += 3.3;
            } else if (score >= 75) {
                gpa += 3.0;
            } else if (score >= 70) {
                gpa += 2.7;
            } else if (score >= 67) {
                gpa += 2.3;
            } else if (score >= 65) {
                gpa += 2.0;
            } else if (score >= 62) {
                gpa += 1.7;
            } else if (score >= 60) {
                gpa += 1.0;
            }
        }
        cout << fixed << setprecision(2) << gpa / N << endl;
    }
}

