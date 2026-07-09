#include <cstdio>
using namespace std;

const int N = 100010;
int a[N];
int stk[N]; // monotonic stack storing values

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int tt = 0; // stack top pointer, 1-indexed
    for (int i = 0; i < n; i++) {
        while (tt > 0 && stk[tt] >= a[i]) tt--;
        if (i > 0) printf(" ");
        if (tt == 0) printf("-1");
        else printf("%d", stk[tt]);
        stk[++tt] = a[i];
    }
    printf("\n");
    return 0;
}
