#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int L;
    char op;
    cin >> L >> op;

    double grid[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> grid[i][j];
        }
    }

    double sum = 0.0;
    for (int j = 0; j < 12; j++) {
        sum += grid[L][j];
    }

    cout << fixed << setprecision(1);
    if (op == 'S') {
        cout << sum << endl;
    } else {
        cout << sum / 12.0 << endl;
    }

    return 0;
}
