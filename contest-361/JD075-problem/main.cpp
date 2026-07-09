#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, word, longest;
    getline(cin, s);
    for (char c : s) {
        if (isalpha(c) || c == '-') {
            word += c;
        } else {
            if (word.size() > longest.size())
                longest = word;
            word.clear();
        }
    }
    if (word.size() > longest.size())
        longest = word;
    cout << longest;
    return 0;
}
