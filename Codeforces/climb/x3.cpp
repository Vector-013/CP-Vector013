#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    if (v[1] == 0)
    {
        dp[1][0] = 1;
        dp[1][1] = 1;
    }
    else
    {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
    // cout << dp[1][0] << ' ' << dp[1][1] << '\n';
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == v[i - 1])
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][0] = dp[i][0] % mod;
        }
        if (v[i] == v[i - 2] + 1)
        {
            dp[i][0] += dp[i - 1][1];
            dp[i][0] = dp[i][0] % mod;
        }
        if (v[i] != v[i - 1] && v[i] != v[i - 2] + 1)
        {
            dp[i][0] = 0;
        }

        dp[i][1] += dp[i - 1][0];
        dp[i][1] = dp[i][1] % mod;
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}