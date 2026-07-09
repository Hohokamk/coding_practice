#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> subsets;

    // Generate all non-empty subsets
    for (int mask = 1; mask < (1 << n); mask++) {
        string s;
        for (int i = 1; i <= n; i++) {
            if (mask & (1 << (i - 1))) {
                if (!s.empty()) s += ' ';
                s += to_string(i);
            }
        }
        subsets.push_back(s);
    }

    sort(subsets.begin(), subsets.end());

    for (const string& s : subsets) {
        cout << s << '\n';
    }

    return 0;
}
