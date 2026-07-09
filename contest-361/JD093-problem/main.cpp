#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 1, b = 2;
    if (n == 1) {
        cout << a << endl;
        return 0;
    }
    if (n == 2) {
        cout << b << endl;
        return 0;
    }

    int c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;

    return 0;
}
