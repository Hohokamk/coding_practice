#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, size;
    cin >> n >> size;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
