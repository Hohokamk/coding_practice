#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long median = a[n / 2], ans = 0;
    for (long long x : a) ans += abs(x - median);
    cout << ans;
    return 0;
}
