#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int st[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            st[++tt] = x;
        } else if (op == "pop") {
            if (tt > 0) tt--;
        } else if (op == "query") {
            cout << st[tt] << '\n';
        } else if (op == "empty") {
            cout << (tt == 0 ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
