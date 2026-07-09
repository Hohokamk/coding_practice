#include <iostream>
using namespace std;

const int N = 100010;
int q[N];
int hh = 0, tt = -1;

int main() {
    int n;
    cin >> n;
    string op;
    while (n--) {
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q[++tt] = x;
        } else if (op == "pop") {
            hh++;
        } else if (op == "query") {
            cout << q[hh] << endl;
        } else if (op == "empty") {
            cout << (hh > tt ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
