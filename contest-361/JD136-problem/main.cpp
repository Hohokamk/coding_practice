#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    string pattern, text;

    cin >> n >> pattern >> m >> text;

    // Build next array (LPS - longest proper prefix which is also suffix)
    vector<int> next(n);
    next[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }

    // KMP search
    vector<int> positions;
    for (int i = 0, j = 0; i < m; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == n) {
            positions.push_back(i - n + 1);
            j = next[j - 1];
        }
    }

    // Output
    for (size_t k = 0; k < positions.size(); k++) {
        if (k > 0) cout << " ";
        cout << positions[k];
    }
    cout << endl;

    return 0;
}
