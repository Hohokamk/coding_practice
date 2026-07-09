#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 50005;
int parent[MAXN];
int d[MAXN];

int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]);
        d[x] = (d[x] + d[parent[x]]) % 3;
        parent[x] = root;
    }
    return parent[x];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        d[i] = 0;
    }

    int falseCount = 0;

    for (int i = 0; i < m; i++) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);

        if (x > n || y > n) {
            falseCount++;
            continue;
        }

        if (op == 2 && x == y) {
            falseCount++;
            continue;
        }

        int rx = find(x);
        int ry = find(y);

        if (op == 1) {
            if (rx == ry) {
                if ((d[x] - d[y] + 3) % 3 != 0) {
                    falseCount++;
                }
            } else {
                parent[rx] = ry;
                d[rx] = (d[y] - d[x] + 3) % 3;
            }
        } else {
            if (rx == ry) {
                if ((d[x] - d[y] + 3) % 3 != 1) {
                    falseCount++;
                }
            } else {
                parent[rx] = ry;
                d[rx] = (d[y] - d[x] + 4) % 3;
            }
        }
    }

    printf("%d\n", falseCount);
    return 0;
}
