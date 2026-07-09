#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];
int q[N]; // monotonic queue storing indices
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Minimums
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        // Remove out-of-window elements from front
        if (hh <= tt && q[hh] < i - k + 1) ++hh;
        // Maintain increasing queue for minimums
        while (hh <= tt && a[q[tt]] >= a[i]) --tt;
        q[++tt] = i;
        if (i >= k - 1) {
            if (i > k - 1) cout << ' ';
            cout << a[q[hh]];
        }
    }
    cout << '\n';

    // Maximums
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && q[hh] < i - k + 1) ++hh;
        // Maintain decreasing queue for maximums
        while (hh <= tt && a[q[tt]] <= a[i]) --tt;
        q[++tt] = i;
        if (i >= k - 1) {
            if (i > k - 1) cout << ' ';
            cout << a[q[hh]];
        }
    }
    cout << '\n';

    return 0;
}
