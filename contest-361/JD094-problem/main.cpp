#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // dp[i][j] = number of paths from (0,0) to (i,j)
    long long dp[21][21] = {0};

    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 0; j <= m; j++) dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
