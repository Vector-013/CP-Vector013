#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;
#define int long long

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;
    vector<int> dp(m, 0ll);
    vector<int> pre(m + 1, 0ll);
    for (int i = 0; i < m; ++i)
        pre[i + 1] = (pre[i] + (int)(s[0][i] == 'X')) % mod;
    for (int i = 0; i < m; ++i)
    {
        if (s[0][i] == 'X')
            dp[i] = (dp[i] + (pre[min(m, i + 1ll + d)] - pre[max(0ll, i - d)]) % mod) % mod;
    }

    for (int r = 1; r < n; ++r)
    {
        vector<int> pre(m + 1, 0ll), ndp(m, 0ll);
        for (int i = 0; i < m; ++i)
            pre[i + 1] = (pre[i] + dp[i]) % mod;

        for (int i = 0; i < m; ++i)
            if (s[r][i] == 'X')
                ndp[i] = (ndp[i] + (pre[min(m, i + 1ll + (d - 1ll))] - pre[max(0ll, i - (d - 1ll))]) % mod) % mod;
        dp = ndp;
        pre.assign(m + 1, 0ll);
        ndp.assign(m, 0ll);
        for (int i = 0; i < m; ++i)
            pre[i + 1] = (pre[i] + dp[i]) % mod;
        for (int i = 0; i < m; ++i)
            if (s[r][i] == 'X')
                ndp[i] = (ndp[i] + (pre[min(m, i + 1ll + d)] - pre[max(0ll, i - d)]) % mod) % mod;
        dp = ndp;
        for(int i = 0; i < m; i++){
            dp[i] = (dp[i] + mod) % mod;
        }
    }
    int ans = 0ll;
    for (int x : dp)
    {
        // assert(x >= 0);
        ans = (ans + x) % mod;
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}