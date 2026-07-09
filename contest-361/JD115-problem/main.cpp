#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int i = 0;
    for (int j = 0; j < m && i < n; ++j) {
        if (a[i] == b[j]) ++i;
    }

    if (i == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
