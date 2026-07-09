#include <iostream>
using namespace std;

const int N = 100010;
int head = -1, idx = 0;
int val[N], ne[N];
int ins[N]; // ins[k] = array index of k-th insertion (1-indexed)

void insert_head(int x) {
    val[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert_after(int k, int x) {
    // k is array index
    val[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// In the original AcWing problem, D k deletes the element AFTER the k-th insertion
// In this problem: D k deletes the element before the k-th insertion (ins[k-1])
void delete_at(int target) {
    if (target == head) {
        head = ne[head];
        return;
    }
    for (int i = head; i != -1; i = ne[i]) {
        if (ne[i] == target) {
            ne[i] = ne[target];
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    int ins_cnt = 0;

    while (m--) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            insert_head(x);
            ins[++ins_cnt] = idx - 1;
        } else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            insert_after(ins[k], x);
            ins[++ins_cnt] = idx - 1;
        } else if (op == 'D') {
            int k;
            cin >> k;
            // Delete the (k-1)-th insertion (element before k-th in insertion order)
            if (k > 1) {
                delete_at(ins[k - 1]);
            }
        }
    }

    // Output: space-separated on one line
    bool first = true;
    for (int i = head; i != -1; i = ne[i]) {
        if (!first) cout << ' ';
        cout << val[i];
        first = false;
    }
    cout << '\n';

    return 0;
}
