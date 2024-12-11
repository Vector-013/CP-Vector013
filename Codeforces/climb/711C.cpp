#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const ll mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for (int j = 1; j <= k; j++)
    {
        ll cur = 1;
        for (int i = 0; i <= n; i++)
        {
            dp[i][j] = cur;
            if (i < n)
                cur = (cur + dp[n - i - 1][j - 1]) % mod;
        }
    }
    cout << dp[n][k] << '\n';
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