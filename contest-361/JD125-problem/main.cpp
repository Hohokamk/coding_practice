#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ops(n);
    vector<int> xs;

    for (int i = 0; i < n; i++) {
        cin >> ops[i].first >> ops[i].second;
        xs.push_back(ops[i].first);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    vector<long long> sum(xs.size() + 1);
    for (auto& p : ops) {
        int idx = lower_bound(xs.begin(), xs.end(), p.first) - xs.begin() + 1;
        sum[idx] += p.second;
    }

    for (int i = 1; i <= (int)xs.size(); i++) {
        sum[i] += sum[i - 1];
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        int li = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        int ri = upper_bound(xs.begin(), xs.end(), r) - xs.begin();
        cout << sum[ri] - sum[li] << '\n';
    }

    return 0;
}
