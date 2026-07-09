#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char op;
    cin >> op;

    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            double val;
            cin >> val;
            if (i + j > 11) {
                sum += val;
                count++;
            }
        }
    }

    cout << fixed << setprecision(1);
    if (op == 'S') {
        cout << sum << endl;
    } else {
        cout << sum / count << endl;
    }

    return 0;
}
