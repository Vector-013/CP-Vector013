#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7;
int paths(int i, int j, vector<vector<int>> &dp, int n)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1 && j != n - 1)
    {
        dp[i][j] = paths(i, j + 1, dp, n) % mod;
    }
    else if (j == n - 1 && i != n - 1)
    {
        dp[i][j] = paths(i + 1, j, dp, n) % mod;
    }
    else
    {
        dp[i][j] = (paths(i, j + 1, dp, n) % mod + paths(i + 1, j, dp, n) % mod) % mod;
    }
    return dp[i][j];
}
int main()
{
    int n;
    cin >> n;
    char z[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> z[i][j];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (z[i][j] == '*')
                dp[i][j] = 0;

    if (dp[n - 1][n - 1] != 0)
        dp[n - 1][n - 1] = 1;
    int ans = paths(0, 0, dp, n);
    cout << ans << '\n';
}