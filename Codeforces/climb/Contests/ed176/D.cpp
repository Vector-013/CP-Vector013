#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long
ll dp[62][62];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < 62; i++)
        for (int j = 0; j < 62; j++)
            dp[i][j] = 9e18;

    dp[0][0] = 0;
    for (int k = 1; k < 62; ++k)
    {
        for (int i = 61; i >= 0; i--)
            for (int j = 61; j >= 0; j--)
            {
                if (dp[i][j] < (ll)9e18)
                {
                    if (i + k < 62)
                        dp[i + k][j] = min(dp[i + k][j], dp[i][j] | 1LL << k);
                    if (j + k < 62)
                        dp[i][j + k] = min(dp[i][j + k], dp[i][j] | 1LL << k);
                }
            }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll ans = 9e18;
        for (int i = 0; i < 62; i++)
            for (int j = 0; j < 62; j++)
                if ((x >> i) == (y >> j))
                    ans = min(ans, dp[i][j]);
        cout << ans << "\n";
    }
}