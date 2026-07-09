#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, target;
    cin >> target >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool hasans = false;
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i + 1] == a[i])
            continue;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (a[j + 1] == a[j])
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (k < n - 1 && a[k + 1] == a[k])
                    k++;
                if (a[i] + a[j] + a[k] == target)
                {
                    cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
                    hasans = true;
                }
            }
        }
    }
    return 0;
}