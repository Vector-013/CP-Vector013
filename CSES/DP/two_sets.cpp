#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7;
int main()
{
    int n, k;
    cin >> n;
    int t = n * (n + 1) / 2;
    if (t & 1)
    {
        cout << 0 << endl;
        return 0;
    }
    t /= 2;

    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            k = j - i;
            if (k >= 0)
            {
                (dp[i][j] += dp[i - 1][k]) %= mod;
            }
        }
    }
    cout << dp[n - 1][t] << endl;
}