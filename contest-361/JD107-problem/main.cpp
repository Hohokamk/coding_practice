#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int x;
        cin >> x;

        // Find leftmost position (first >= x where a[mid] == x)
        int left = -1;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] >= x) {
                if (a[mid] == x) left = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (left == -1 || a[left] != x) {
            cout << "-1 -1" << endl;
            continue;
        }

        // Find rightmost position (last <= x where a[mid] == x)
        int right = left;
        lo = left;
        hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] <= x) {
                if (a[mid] == x) right = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << left << " " << right << endl;
    }

    return 0;
}
