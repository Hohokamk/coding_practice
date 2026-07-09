#include <iostream>
using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m <= 0 && n <= 0) break;
        if (m > n) {
            int t = m;
            m = n;
            n = t;
        }
        int sum = 0;
        for (int i = m; i <= n; ++i) {
            if (i > m) cout << " ";
            cout << i;
            sum += i;
        }
        cout << " Sum=" << sum << endl;
    }
    return 0;
}
