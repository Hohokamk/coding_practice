#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a, b;
    int x;

    while (cin >> x && x != -1) {
        a.push_back(x);
    }

    while (cin >> x && x != -1) {
        b.push_back(x);
    }

    vector<int> result;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }

    while (i < n) {
        result.push_back(a[i++]);
    }

    while (j < m) {
        result.push_back(b[j++]);
    }

    for (int k = 0; k < (int)result.size(); k++) {
        if (k > 0) cout << ' ';
        cout << result[k];
    }
    cout << endl;

    return 0;
}
