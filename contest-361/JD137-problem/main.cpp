#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N];      // heap: value at heap position
int ph[N];     // ph[k] = heap position of k-th insertion
int hp[N];     // hp[pos] = insertion index of element at heap position
int cnt;       // heap size
int idx;       // insertion counter

void heap_swap(int a, int b) {
    // a, b are heap positions
    swap(h[a], h[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char op[5];
    while (n--) {
        scanf("%s", op);
        if (op[0] == 'I') {
            int x;
            scanf("%d", &x);
            cnt++; idx++;
            h[cnt] = x;
            ph[idx] = cnt;
            hp[cnt] = idx;
            up(cnt);
        } else if (op[0] == 'P' && op[1] == 'M') {
            printf("%d\n", h[1]);
        } else if (op[0] == 'D' && op[1] == 'M') {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        } else if (op[0] == 'D') {
            int k;
            scanf("%d", &k);
            int p = ph[k]; // heap position of k-th insertion
            heap_swap(p, cnt);
            cnt--;
            up(p);
            down(p);
        } else if (op[0] == 'C') {
            int k, x;
            scanf("%d%d", &k, &x);
            int p = ph[k]; // heap position of k-th insertion
            h[p] = x;
            up(p);
            down(p);
        }
    }
    return 0;
}
