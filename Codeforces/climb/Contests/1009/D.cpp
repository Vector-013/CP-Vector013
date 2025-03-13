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
    int n, m;
    cin >> n >> m;
    vector<ll> c(n), r(n);
    for (auto &x : c)
        cin >> x;
    for (auto &x : r)
        cin >> x;
    map<ll, ll> mp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = c[i] - r[i]; j <= c[i] + r[i]; ++j)
        {
            ll y = (long long)(sqrtl(r[i] * r[i] - (j - c[i]) * (j - c[i])));
            mp[j] = max(mp[j], 2 * y + 1);
        }
    }
    ll ans = 0;
    for (auto [x, y] : mp)
        ans += y;
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