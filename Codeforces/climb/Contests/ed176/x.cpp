#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
long long dp[62][62];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 62; i++)
        for (int j = 0; j < 62; j++)
            dp[i][j] = 9e18;
    dp[0][0] = 0;
    for (int k = 1; k < 62; k++)
    {
        for (int i = 61; i >= 0; i--)
            for (int j = 61; j >= 0; j--)
                if (dp[i][j] < (long long)9e18)
                {
                    if (i + k < 62)
                        dp[i + k][j] = min(dp[i + k][j], dp[i][j] | 1LL << k);
                    if (j + k < 62)
                        dp[i][j + k] = min(dp[i][j + k], dp[i][j] | 1LL << k);
                }
    }
    int T;
    cin >> T;
    for (; T--;)
    {
        long long x, y;
        cin >> x >> y;
        long long ans = 9e18;
        for (int i = 0; i < 62; i++)
            for (int j = 0; j < 62; j++)
                if ((x >> i) == (y >> j))
                    ans = min(ans, dp[i][j]);
        cout << ans << "\n";
    }
}
