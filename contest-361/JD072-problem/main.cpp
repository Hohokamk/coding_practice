#include <iostream>
#include <string>
using namespace std;

int main() {
    string p1, p2;
    cin >> p1 >> p2;

    if (p1 == p2) {
        cout << "Tie" << endl;
    } else if ((p1 == "Rock" && p2 == "Scissors") ||
               (p1 == "Scissors" && p2 == "Paper") ||
               (p1 == "Paper" && p2 == "Rock")) {
        cout << "Player1" << endl;
    } else {
        cout << "Player2" << endl;
    }

    return 0;
}
