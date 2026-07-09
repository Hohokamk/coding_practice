#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isSmaller(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

int main() {
    string a, b;
    cin >> a >> b;

    bool negative = false;
    if (isSmaller(a, b)) {
        swap(a, b);
        negative = true;
    }

    string result;
    int n1 = a.length(), n2 = b.length();
    int diff = n1 - n2;
    int carry = 0;

    for (int i = n2 - 1; i >= 0; i--) {
        int sub = (a[i + diff] - '0') - (b[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    for (int i = diff - 1; i >= 0; i--) {
        int sub = (a[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    reverse(result.begin(), result.end());

    // Remove leading zeros
    size_t pos = 0;
    while (pos < result.length() - 1 && result[pos] == '0')
        pos++;
    result = result.substr(pos);

    if (negative)
        cout << "-";
    cout << result << endl;

    return 0;
}
