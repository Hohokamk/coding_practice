#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string res;

    while (i >= 0 || j >= 0 || carry) {
        int da = i >= 0 ? a[i--] - '0' : 0;
        int db = j >= 0 ? b[j--] - '0' : 0;
        int s = da + db + carry;
        carry = s / 10;
        res.push_back('0' + (s % 10));
    }

    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
