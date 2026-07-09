#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = (c == 'z') ? 'a' : c + 1;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c == 'Z') ? 'A' : c + 1;
        } else if (c >= '0' && c <= '9') {
            c = (c == '9') ? '0' : c + 1;
        }
    }
    cout << s << endl;
    return 0;
}
