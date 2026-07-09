#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string Left[3], Right[3], Result[3];
bool judge(char m, bool islight)
{
    string c;
    c.push_back(m); // 把char 转换为string类型

    for (int i = 0; i < 3; i++)
    {
        string l = Left[i], r = Right[i];
        if (!islight)
            swap(l, r);
        switch (Result[i][0])
        {
        case 'e':
            if (l.find(c) != string::npos || r.find(c) != string::npos)
                return false;
            break;
        case 'u':
            if (r.find(c) == string::npos)
                return false;
            break;
        case 'd':
            if (l.find(c) == string::npos)
                return false;
            break;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 3; i++)
            cin >> Left[i] >> Right[i] >> Result[i];

        for (int icoin = 'A'; icoin <= 'L'; icoin++)
        {
            if (judge(icoin, true))
            {
                cout << icoin << " is the counterfeit coin and it is light." << endl;
                break;
            }
            else if (judge(icoin, false))
            {
                cout << icoin << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }
}

// 暴力枚举12*2种一个个判断

// 为啥还是过不了