#include <iostream>
using namespace std;

int main() {
    int V;
    cin >> V;
    int N = V;
    for (int i = 0; i < 10; i++) {
        cout << "N[" << i << "] = " << N << endl;
        N *= 2;
    }
    return 0;
}
