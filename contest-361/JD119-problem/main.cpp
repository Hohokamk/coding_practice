#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> comb;

void dfs(int start) {
    if ((int)comb.size() == m) {
        for (int i = 0; i < m; i++) {
            if (i > 0) cout << " ";
            cout << comb[i];
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++) {
        comb.push_back(i);
        dfs(i + 1);
        comb.pop_back();
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}
