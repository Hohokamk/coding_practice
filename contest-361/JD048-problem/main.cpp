#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long a = 0, b = 1;
    if (N == 0) {
        cout << a << endl;
        return 0;
    }
    for (int i = 2; i <= N; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << b << endl;
    return 0;
}
