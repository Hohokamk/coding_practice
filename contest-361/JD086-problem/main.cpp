#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, size;
    cin >> n >> m >> size;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int limit = min(size, n);
    for (int i = 0; i < limit; i++) {
        b[i] = a[i];
    }

    for (int i = 0; i < m; i++) {
        if (i > 0) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}
