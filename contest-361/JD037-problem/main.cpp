#include <iostream>
using namespace std;

int main() {
    long long A;
    cin >> A;
    long long N = 0;
    int x;
    while (cin >> x) {
        if (x > 0) {
            N = x;
            break;
        }
    }
    long long sum = N * A + N * (N - 1) / 2;
    cout << sum << endl;
    return 0;
}
