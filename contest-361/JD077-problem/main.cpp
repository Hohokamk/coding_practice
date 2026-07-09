#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    for (char c : s) {
        if (cnt[c] == 1) {
            cout << c << endl;
            return 0;
        }
    }

    cout << "no" << endl;
    return 0;
}
