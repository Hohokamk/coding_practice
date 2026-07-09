#include <cstdio>
using namespace std;

const int MAXN = 2005;
int a[MAXN][MAXN];
long long diff[MAXN][MAXN];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            printf("%lld", (long long)a[i][j] + diff[i][j]);
            if (j < m) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
