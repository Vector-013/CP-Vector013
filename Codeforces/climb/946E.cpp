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
    ll m, x;
    cin >> m >> x;
    vector<ll> dp;
    dp.push_back(0);
    ll th = 0, ans = 0;
    for (int i = 0; i < m; ++i)
    {
        ll c, h;
        cin >> c >> h;
        th += h;
        dp.resize(th + 1, -1);
        for (int k = th; k >= h; k--)
            if (dp[k - h] >= c)
                dp[k] = max(dp[k], dp[k - h] - c);
        for (int k = th; k >= 0; k--)
            if (dp[k] >= 0)
                dp[k] += x;
    }
    for (int h = 0; h <= th; h++)
        if (dp[h] >= 0)
            ans = h;
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