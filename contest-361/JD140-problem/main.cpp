#include <cstdio>
using namespace std;

const int MAXN = 50010;
int parent[MAXN * 3 + 10];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i++) parent[i] = i;
    while (k--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || x < 1 || y < 1) {
            ans++;
            continue;
        }
        if (d == 1) {
            if (find(x) == find(y + n) || find(x) == find(y + 2 * n))
                ans++;
            else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        } else if (d == 2) {
            if (find(x) == find(y) || find(x) == find(y + 2 * n))
                ans++;
            else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
