#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int start = A * 60 + B;
    int end = C * 60 + D;
    int diff = end - start;
    if (diff <= 0) {
        diff += 24 * 60;
    }
    cout << diff / 60 << ":" << diff % 60 << endl;
    return 0;
}
