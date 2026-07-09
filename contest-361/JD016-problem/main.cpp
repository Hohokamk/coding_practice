#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(1);
    if (a + b > c && a + c > b && b + c > a)
        cout << "Perimeter = " << a + b + c;
    else
        cout << "Area = " << (a + b) * c / 2.0;
    return 0;
}
