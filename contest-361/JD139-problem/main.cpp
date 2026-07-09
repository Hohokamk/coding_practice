#include <cstdio>
using namespace std;

const int N = 100010;
int parent[N], sz[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    char op[5];
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'C') {
            int a, b;
            scanf("%d%d", &a, &b);
            a = find(a); b = find(b);
            if (a != b) {
                if (sz[a] < sz[b]) { int t = a; a = b; b = t; }
                parent[b] = a;
                sz[a] += sz[b];
            }
        } else if (op[1] == '1') { // Q1
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%s\n", find(a) == find(b) ? "Yes" : "No");
        } else { // Q2
            int a;
            scanf("%d", &a);
            printf("%d\n", sz[find(a)]);
        }
    }
    return 0;
}
