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
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ll s = 0;
        for (int j = 0; j < m; ++j)
        {
            ll x;
            cin >> x;
            s += x;
            ans += (m - j) * x;
        }
        a[i] = s;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        ans += a[i] * i * m;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
