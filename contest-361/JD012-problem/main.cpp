#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    const double PI = 3.14159;
    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << a * c / 2.0 << endl;
    cout << "CIRCULO: " << PI * c * c << endl;
    cout << "TRAPEZIO: " << (a + b) * c / 2.0 << endl;
    cout << "QUADRADO: " << b * b << endl;
    cout << "RETANGULO: " << a * b << endl;
    return 0;
}
