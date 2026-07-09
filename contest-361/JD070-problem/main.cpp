#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    int n = a.size();
    string b;
    b.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = static_cast<char>(a[i] + a[i + 1]);
    }
    b[n - 1] = static_cast<char>(a[n - 1] + a[0]);
    cout << b;
    return 0;
}
