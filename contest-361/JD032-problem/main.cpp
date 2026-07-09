#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    int start = (X % 2 == 0) ? X + 1 : X + 2;
    for (int i = 0; i < 6; i++) {
        cout << start + 2 * i << '\n';
    }
    return 0;
}
