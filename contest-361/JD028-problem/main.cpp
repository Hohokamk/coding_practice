#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double income;
    cin >> income;

    if (income <= 2000.00) {
        cout << "Isento" << endl;
        return 0;
    }

    double tax = 0.0;

    if (income > 4500.00) {
        tax += (income - 4500.00) * 0.28;
        income = 4500.00;
    }
    if (income > 3000.00) {
        tax += (income - 3000.00) * 0.18;
        income = 3000.00;
    }
    if (income > 2000.00) {
        tax += (income - 2000.00) * 0.08;
    }

    cout << "R$ " << fixed << setprecision(2) << tax << endl;

    return 0;
}
