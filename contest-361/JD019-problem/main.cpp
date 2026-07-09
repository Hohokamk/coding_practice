#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double p[] = {0, 4.00, 4.50, 5.00, 2.00, 1.50};
    int x, y;
    cin >> x >> y;
    cout << fixed << setprecision(2);
    cout << "Total: R$ " << p[x] * y;
    return 0;
}
