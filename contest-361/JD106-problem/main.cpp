#include <iostream>
#include <vector>
using namespace std;

long long merge_count(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = merge_count(a, l, mid) + merge_count(a, mid + 1, r);

    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l, k = 0; i <= r; ++i, ++k) a[i] = tmp[k];
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << merge_count(a, 0, n - 1) << endl;
    return 0;
}
