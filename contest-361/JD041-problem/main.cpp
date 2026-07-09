#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            cout << num;
            num++;
            if (j < M - 2) cout << " ";
        }
        if (M > 1) cout << " ";
        cout << "SWORD";
        num++;
        cout << endl;
    }

    return 0;
}
