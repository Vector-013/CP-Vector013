#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, b;
    int dp[501][501];
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            if (i == j)
            {
                dp[i][j] == 0;
                continue;
            }
            if (i == 1 || j == 1)
                dp[i][j] = i + j - 2;
            else
            {
                int mini = 2e9;
                for (int a = 1; a < i; a++)
                    mini = min(mini, dp[i - a][j] + dp[a][j]);
                for (int a = 1; a < j; a++)
                    mini = min(mini, dp[i][a] + dp[i][j - a]);
                dp[i][j] = mini + 1;
            }
        }
    }
    cin >> a >> b;
    cout << dp[a][b];
}