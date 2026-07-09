#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    int swords = 0, blades = 0, spears = 0;

    for (int i = 0; i < n; ++i) {
        int cnt;
        char type;
        cin >> cnt >> type;

        if (type == 'C') {
            swords += cnt;
        } else if (type == 'R') {
            blades += cnt;
        } else if (type == 'F') {
            spears += cnt;
        }
    }

    int total = swords + blades + spears;

    cout << "Total: " << total << " weapons" << endl;
    cout << "Total swords: " << swords << endl;
    cout << "Total blades: " << blades << endl;
    cout << "Total spears: " << spears << endl;

    cout << fixed << setprecision(2);
    if (total == 0) {
        cout << "Percentage of swords: 0.00 %" << endl;
        cout << "Percentage of blades: 0.00 %" << endl;
        cout << "Percentage of spears: 0.00 %" << endl;
    } else {
        cout << "Percentage of swords: " << (100.0 * swords / total) << " %" << endl;
        cout << "Percentage of blades: " << (100.0 * blades / total) << " %" << endl;
        cout << "Percentage of spears: " << (100.0 * spears / total) << " %" << endl;
    }

    return 0;
}
