#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int target, n;
    cin >> target >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] + a[j] == target)
            {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}