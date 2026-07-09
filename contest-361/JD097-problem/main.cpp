#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a = 0, b = 1;
    while (n--) {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    return 0;
}
