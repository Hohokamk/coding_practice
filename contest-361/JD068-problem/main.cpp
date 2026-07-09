#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (size_t i = 0; i < s.size(); i++) {
        if (i > 0) cout << " ";
        cout << s[i];
    }
    return 0;
}
