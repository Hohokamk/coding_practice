#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int points = 0;
    int last_point = -2e9 - 5;

    for (const auto& interval : intervals) {
        if (interval.first > last_point) {
            last_point = interval.second;
            ++points;
        }
    }

    cout << points << '\n';

    return 0;
}
