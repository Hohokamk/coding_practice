#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line, a, b;
    getline(cin, line);
    getline(cin, a);
    getline(cin, b);

    stringstream ss(line);
    string word;
    bool first = true;
    while (ss >> word) {
        if (!first) cout << " ";
        if (word == a) cout << b;
        else cout << word;
        first = false;
    }
    cout << endl;
    return 0;
}
