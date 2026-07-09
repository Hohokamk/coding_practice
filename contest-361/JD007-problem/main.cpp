#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int num, days;
    double rate;
    cin >> num >> days >> rate;
    cout << "NUMBER = " << num << endl;
    cout << fixed << setprecision(2);
    cout << "SALARY = U$ " << days * rate;
    return 0;
}
