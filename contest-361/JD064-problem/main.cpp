#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << setw(3) << abs(i - j) + 1;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
