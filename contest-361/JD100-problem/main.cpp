#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    int x;
    while (cin >> x && x != -1) {
        a.push_back(x);
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        if (i < (int)a.size() - 1) cout << " ";
        cout << a[i];
    }
    return 0;
}
