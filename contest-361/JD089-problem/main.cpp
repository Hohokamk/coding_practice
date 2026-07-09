#include <iostream>
using namespace std;
int main() {
    int row, col;
    cin >> row >> col;
    int x;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> x;
            if (j > 0) cout << " ";
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
