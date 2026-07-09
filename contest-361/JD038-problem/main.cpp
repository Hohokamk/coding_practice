#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int maxVal, maxPos = 1;
    cin >> maxVal;
    for (int i = 2; i <= N; i++) {
        int x;
        cin >> x;
        if (x > maxVal) {
            maxVal = x;
            maxPos = i;
        }
    }
    cout << maxVal << endl;
    cout << maxPos << endl;
    return 0;
}
