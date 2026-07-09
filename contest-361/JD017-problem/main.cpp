#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (b > a) cout << b - a;
    else if (a == b) cout << 24;
    else cout << 24 - a + b;
    return 0;
}
