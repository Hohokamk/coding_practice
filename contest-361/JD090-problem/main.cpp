#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a + l, a + r + 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
