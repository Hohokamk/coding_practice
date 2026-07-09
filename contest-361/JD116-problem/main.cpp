#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> lastPos;
    int ans = 0;
    int left = 0;
    int val;

    for (int right = 0; right < n; right++) {
        cin >> val;
        auto it = lastPos.find(val);
        if (it != lastPos.end() && it->second >= left) {
            left = it->second + 1;
        }
        lastPos[val] = right;
        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';

    return 0;
}
