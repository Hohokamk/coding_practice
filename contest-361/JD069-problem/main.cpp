#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char c;
    cin >> s >> c;
    for (char &ch : s) {
        if (ch == c) ch = '#';
    }
    cout << s << endl;
    return 0;
}
