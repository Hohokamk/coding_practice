#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        unsigned int x;
        cin >> x;

        int cnt = 0;
        while (x) {
            x &= x - 1;
            cnt++;
        }

        cout << cnt;
        if (i < n - 1) cout << ' ';
    }
    cout << '\n';

    return 0;
}
