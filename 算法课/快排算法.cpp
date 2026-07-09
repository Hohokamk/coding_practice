#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
void quick_sort(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pvot = a[l];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (a[i] < pvot);
        do
            j--;
        while (a[j] > pvot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        quick_sort(a, l, j);
        quick_sort(a, j + 1, r);
    }
}

int main()
{
    int n;
    int a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}