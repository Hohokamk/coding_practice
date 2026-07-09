#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double salary;
    cin >> salary;

    int p;
    if (salary >= 0 && salary <= 400) {
        p = 15;
    } else if (salary >= 400.01 && salary <= 800) {
        p = 12;
    } else if (salary >= 800.01 && salary <= 1200) {
        p = 10;
    } else if (salary >= 1200.01 && salary <= 2000) {
        p = 7;
    } else {
        p = 4;
    }

    double increase = salary * p / 100.0;
    double newSalary = salary + increase;

    cout << fixed << setprecision(2);
    cout << "New salary: " << newSalary << endl;
    cout << "Increase: " << increase << endl;
    cout << "Percentage: " << p << " %" << endl;

    return 0;
}
