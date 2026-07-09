#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;
int a[MAXN], tmp[MAXN];

void mergeSort(int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = tmp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
