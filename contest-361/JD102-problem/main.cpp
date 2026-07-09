#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

struct Record {
    int x;
    double y;
    string z;
};

int main() {
    int n;
    cin >> n;
    vector<Record> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].x >> records[i].y >> records[i].z;
    }
    sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    cout << fixed << setprecision(2);
    for (const auto& r : records) {
        cout << r.x << " " << r.y << " " << r.z << "\n";
    }
    return 0;
}
