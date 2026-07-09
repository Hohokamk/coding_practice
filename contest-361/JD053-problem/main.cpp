#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    // Known perfect numbers: 6, 28, 496, 8128, 33550336
    // For typical contest N (< 10^7), only first 4 matter
    int perfect[] = {6, 28, 496, 8128, 33550336};
    for (int i = 0; i < 5; i++) {
        if (perfect[i] <= n) {
            printf("%d\n", perfect[i]);
        }
    }
    return 0;
}
