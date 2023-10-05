#include <iostream>
#include <vector>
const int mod = 1e9 + 7;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (x[0] == 0)
    {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][x[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (x[i] != 0)
        {
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % mod;
            if (x[i] != m)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % mod;
            if (x[i] != 1)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % mod;
        }
        else
        {
            for (int k = 1; k <= m; k++)
            {
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % mod;
                if (k != m)
                    dp[i][k] = (dp[i][k] + dp[i - 1][k + 1]) % mod;
                if (k != 1)
                    dp[i][k] = (dp[i][k] + dp[i - 1][k - 1]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout << ans << '\n';
}