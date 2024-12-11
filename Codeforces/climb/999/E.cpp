#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size(), l = c.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (c[i + j - 1] != a[i - 1]));
            }
            if (j > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
            }
        }
    }
    cout << dp[n][m] << '\n';
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