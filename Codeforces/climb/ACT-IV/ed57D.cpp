#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(4, inf));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (s[i - 1] == 'h')
        {
            dp[i][0] = dp[i - 1][0] + a[i - 1];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        if (s[i - 1] == 'a')
        {
            dp[i][1] = dp[i - 1][1] + a[i - 1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
        }
        if (s[i - 1] == 'r')
        {
            dp[i][2] = dp[i - 1][2] + a[i - 1];
            dp[i][3] = min(dp[i - 1][2], dp[i - 1][3]);
        }
        if (s[i - 1] == 'd')
        {
            dp[i][3] = dp[i - 1][3] + a[i - 1];
        }
    }
    ll ans = linf;
    for (int i = 0; i < 4; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}