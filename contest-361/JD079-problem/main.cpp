#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == ".") break;
        int n = s.length();
        for (int p = 1; p <= n; p++) {
            if (n % p != 0) continue;
            int k = n / p;
            string sub = s.substr(0, p);
            bool ok = true;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < p; j++) {
                    if (s[i * p + j] != sub[j]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}
