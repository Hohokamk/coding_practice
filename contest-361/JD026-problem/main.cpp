#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    // Sort sides ascending
    double sides[3] = {a, b, c};
    sort(sides, sides + 3);
    a = sides[0]; b = sides[1]; c = sides[2];

    const double eps = 1e-9;

    if (a + b <= c + eps) {
        cout << "Not a triangle" << endl;
        return 0;
    }

    double a2 = a * a, b2 = b * b, c2 = c * c;

    if (fabs(c2 - a2 - b2) < eps) {
        cout << "Right" << endl;
    } else if (c2 < a2 + b2) {
        cout << "Acute" << endl;
    } else {
        cout << "Obtuse" << endl;
    }

    if (fabs(a - b) < eps && fabs(b - c) < eps) {
        cout << "Equilateral" << endl;
    } else if (fabs(a - b) < eps || fabs(b - c) < eps) {
        cout << "Isosceles" << endl;
    }

    return 0;
}
