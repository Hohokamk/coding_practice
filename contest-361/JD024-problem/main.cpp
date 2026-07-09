#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (B > A && D > A && C + D > A + B && C > 0 && A % 2 == 0) {
        cout << "Accepted" << endl;
    } else {
        cout << "Not accepted" << endl;
    }
    return 0;
}
