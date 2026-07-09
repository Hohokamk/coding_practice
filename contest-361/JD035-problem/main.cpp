#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int in_count = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x >= 10 && x <= 20) {
            ++in_count;
        }
    }
    int out_count = n - in_count;
    cout << in_count << " in" << endl;
    cout << out_count << " out";
    return 0;
}
