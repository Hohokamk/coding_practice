#include <iostream>
using namespace std;
int w, h;
char fogforest[23][23];
int res = 0;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int dfs(int x, int y)
{
}

int main()
{
    while (cin >> w >> h, w || h)
    {
        int startx, starty;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> fogforesrt[i][j];
                if (fogforest[i][j] == '@')
                {
                    startx = i;
                    starty = j;
                }
            }
        }
    }
    cout << dfs(startx, starty) << endl;
}
