#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int mx = a;
    if (b > mx) mx = b;
    if (c > mx) mx = c;
    cout << "Max = " << mx;
    return 0;
}
