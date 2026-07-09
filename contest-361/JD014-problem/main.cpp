#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n << endl;
    int bills[] = {100, 50, 20, 10, 5, 2, 1};
    for (int b : bills) {
        cout << n / b << " nota(s) de R$ " << b << ",00" << endl;
        n %= b;
    }
    return 0;
}
