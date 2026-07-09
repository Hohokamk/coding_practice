#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    int B;
    cin >> A >> B;

    string quotient;
    long long remainder = 0;

    for (char c : A) {
        remainder = remainder * 10 + (c - '0');
        quotient.push_back((remainder / B) + '0');
        remainder %= B;
    }

    // Remove leading zeros from quotient
    size_t pos = 0;
    while (pos + 1 < quotient.size() && quotient[pos] == '0') {
        ++pos;
    }
    cout << quotient.substr(pos) << '\n';
    cout << remainder << '\n';

    return 0;
}
