#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int C;
    char op;
    cin >> C >> op;

    double a[12][12];
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            cin >> a[i][j];

    double sum = 0;
    for (int i = 0; i < 12; ++i)
        sum += a[i][C];

    cout << fixed << setprecision(1);
    if (op == 'S')
        cout << sum << endl;
    else
        cout << sum / 12 << endl;

    return 0;
}
