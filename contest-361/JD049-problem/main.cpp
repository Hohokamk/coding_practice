#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << endl;
        return 0;
    }
    vector<long long> fib(n);
    fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << fib[i];
    }
    cout << endl;
    return 0;
}
