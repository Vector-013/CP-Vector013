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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<ll> f(n, 0);
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        vector<ll> dp(m, linf);
        dp[0] = a[i][0] + 1;
        multiset<ll> s;
        s.insert(dp[0]);
        for (int j = 1; j < m; j++)
        {
            ll curmin = *s.begin();
            dp[j] = min(dp[j], curmin + a[i][j] + 1ll);
            s.insert(dp[j]);
            if (j >= d + 1)
                s.erase(s.lower_bound(dp[j - d - 1]));
        }
        f[i] = dp[m - 1];
    }
    ll ans = linf;
    ll tmp = 0;
    for (int i = 0; i <= k - 1; i++)
        tmp += f[i];
    for (int i = k; i < n; i++)
    {
        ans = min(ans, tmp);
        tmp -= f[i - k];
        tmp += f[i];
    }
    ans = min(ans, tmp);
    cout << ans << '\n';
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