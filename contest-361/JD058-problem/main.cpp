#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char op;
    cin >> op;

    double grid[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> grid[i][j];
        }
    }

    double sum = 0;
    int count = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j > i && i + j > 11) {
                sum += grid[i][j];
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
