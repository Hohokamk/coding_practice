#include <iostream>
#include <string>
using namespace std;

int main() {
    string level1, level2, level3;
    cin >> level1 >> level2 >> level3;

    if (level1 == "vertebrate") {
        if (level2 == "bird") {
            if (level3 == "carnivore") {
                cout << "eagle" << endl;
            } else if (level3 == "herbivore") {
                cout << "dove" << endl;
            }
        } else if (level2 == "mammal") {
            if (level3 == "omnivore") {
                cout << "man" << endl;
            } else if (level3 == "herbivore") {
                cout << "cow" << endl;
            }
        }
    } else if (level1 == "invertebrate") {
        if (level2 == "insect") {
            if (level3 == "hematophagous") {
                cout << "flea" << endl;
            } else if (level3 == "herbivore") {
                cout << "caterpillar" << endl;
            }
        } else if (level2 == "annelid") {
            if (level3 == "hematophagous") {
                cout << "leech" << endl;
            } else if (level3 == "omnivore") {
                cout << "earthworm" << endl;
            }
        }
    }

    return 0;
}
