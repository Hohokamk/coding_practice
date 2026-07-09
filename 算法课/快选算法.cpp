#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int n, k;
int partition(int q[], int l, int r)
{
    int pivot = q[l];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < pivot);
        do
            j--;
        while (q[j] > pivot);
        if (i < j)
            swap(q[i], q[j]);
    }
    return j;
}
int quick_select(int q[], int l, int r, int k)
{
    if (l == r)
        return q[l];
    int j = partition(q, l, r);
    int len = j - l + 1;
    if (k <= len)
        return quick_select(q, l, j, k);
    else
        return quick_select(q, j + 1, r, k - len);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = quick_select(a, 0, n - 1, k);
    cout << ans << endl;
    return 0;
}
