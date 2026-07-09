#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s1, s2;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push") {
            int x;
            cin >> x;
            s1.push(x);
        } else if (cmd == "pop") {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout << s2.top() << endl;
            s2.pop();
        } else if (cmd == "empty") {
            if (s1.empty() && s2.empty())
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}
