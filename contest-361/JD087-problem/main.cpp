#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, size;
    cin >> n >> size;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int l = 0, r = size - 1; l < r; ++l, --r) {
        swap(a[l], a[r]);
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    return 0;
}
