#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    int comma1 = line.find(',');
    int comma2 = line.find(',', comma1 + 1);
    string s = line.substr(0, comma1);
    string s1 = line.substr(comma1 + 1, comma2 - comma1 - 1);
    string s2 = line.substr(comma2 + 1);
    int l = s.find(s1);
    int r = s.rfind(s2);
    if (l != -1 && r != -1 && l + (int)s1.size() <= r)
        cout << r - (l + s1.size()) << endl;
    else
        cout << -1 << endl;
    return 0;
}
