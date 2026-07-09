#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A;
    int B;
    cin >> A >> B;

    if (B == 0) {
        cout << "0" << endl;
        return 0;
    }

    string result;
    int carry = 0;

    for (int i = A.size() - 1; i >= 0; --i) {
        int digit = A[i] - '0';
        int product = digit * B + carry;
        result.push_back((product % 10) + '0');
        carry = product / 10;
    }

    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }

    // Remove trailing zeros from reversal (they were leading zeros originally)
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}
