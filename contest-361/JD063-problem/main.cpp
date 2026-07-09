#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = min({i + 1, j + 1, n - i, n - j});
                printf("%3d", val);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
