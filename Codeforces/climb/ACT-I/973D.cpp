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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;
    ll mn = linf, mx = -1, pref = 0, suff = 0;
    for (int i = 0; i < n; i++)
    {
        pref += a[i];
        suff += a[n - i - 1];
        mn = min(mn, pref / (i + 1));
        mx = max(mx, (suff + i) / (i + 1));
    }
    cout << mx - mn << '\n';
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