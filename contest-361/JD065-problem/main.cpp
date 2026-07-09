#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) cout << " ";
                cout << (1LL << (i + j));
            }
            cout << " " << endl;
        }
        cout << endl;
    }
    return 0;
}
