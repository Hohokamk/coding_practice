#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int j = 0; j < m; ++j) cin >> B[j];

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        int sum = A[i] + B[j];
        if (sum == x) {
            cout << i << ' ' << j;
            break;
        } else if (sum < x) {
            ++i;
        } else {
            --j;
        }
    }

    return 0;
}
