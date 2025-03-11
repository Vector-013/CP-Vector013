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
    vector<ll> p(n + 1, 0), d(n + 1, 0);
    vector<ll> dp(n + 1, 0);
    dp[1] = 1ll;
    ll ans = 0ll;
    for (int i = 2; i <= n; ++i)
        cin >> p[i];
    d[1] = 0ll;
    int dmax = 0;

    for (int i = 2; i <= n; ++i)
        d[i] = d[p[i]] + 1ll;

    dmax = *max_element(d.begin(), d.end());

    vector<ll> s(dmax + 1, 0);
    s[0] = 1;

    vector<vector<ll>> lvls(dmax + 1);
    int v = 1;
    while (v <= n)
    {
        lvls[d[v]].push_back(v);
        v++;
    }
    ll x = 0;

    for (int i = 1; i <= dmax; ++i)
    {
        x = 0;

        for (auto v : lvls[i])
        {
            dp[v] = (p[v] == 1) ? (s[i - 1] % mod) : (s[i - 1] - dp[p[v]] + mod) % mod;
            x = (x + dp[v]) % mod;
        }
        s[i] = x;
    }

    for (int i = 0; i <= dmax; ++i)
        ans = (ans + s[i]) % mod;
    cout << ans % mod << '\n';
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