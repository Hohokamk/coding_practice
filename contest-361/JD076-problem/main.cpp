#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, substr;
    getline(cin, str);
    getline(cin, substr);

    int pos = 0;
    char maxc = str[0];
    for (int i = 1; i < (int)str.size(); ++i) {
        if (str[i] > maxc) {
            maxc = str[i];
            pos = i;
        }
    }

    cout << str.substr(0, pos + 1) << substr << str.substr(pos + 1) << endl;

    return 0;
}
