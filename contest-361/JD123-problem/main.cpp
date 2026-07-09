#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> diff(n + 2, 0);
    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }

    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        a[i] += diff[i];
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
