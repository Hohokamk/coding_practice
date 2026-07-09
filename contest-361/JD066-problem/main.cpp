#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 0, y = 0, d = 0;

    for (int k = 1; k <= n * m; k++) {
        a[x][y] = k;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] != 0) {
            d = (d + 1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << " ";
            cout << a[i][j];
        }
        cout << " " << endl;
    }

    return 0;
}
