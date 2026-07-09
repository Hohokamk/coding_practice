#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int min_val = 2147483640; // near INT_MAX
    int pos = -1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < min_val) {
            min_val = x;
            pos = i;
        }
    }

    cout << "Menor valor: " << min_val << '\n';
    cout << "Posicao: " << pos << '\n';
    return 0;
}
