#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    int ans = 1;
    int r = intervals[0].second;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first <= r) {
            r = max(r, intervals[i].second);
        } else {
            ans++;
            r = intervals[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
