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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<ll> dp(m, linf);
    dp[0] = 0ll;
    for (int i = 0; i < n; i++)
    {
        vector<ll> ndp(m, linf);
        for (int j = 0; j < m; ++j)
        {
            auto zdp = dp;
            for (int x = 0; x < m; ++x)
            {
                if (x)
                {
                    zdp[x] = min(zdp[x], zdp[x - 1]);
                }
                zdp[x] += a[i][(j + x) % m];
                ndp[x] = min(ndp[x], zdp[x] + 1ll * j * k);
            }
        }
        dp = ndp;
    }
    cout << dp[m - 1] << "\n";
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