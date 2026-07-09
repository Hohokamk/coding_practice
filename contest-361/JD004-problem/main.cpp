#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int code, qty;
    double price;
    cin >> code >> qty >> price;
    cout << fixed << setprecision(2);
    cout << "TOTAL = " << qty * price;
    return 0;
}
