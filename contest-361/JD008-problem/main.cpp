#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double dist, fuel;
    cin >> dist >> fuel;
    cout << fixed << setprecision(3);
    cout << dist / fuel << " km/l";
    return 0;
}
