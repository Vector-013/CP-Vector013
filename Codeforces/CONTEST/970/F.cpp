#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const ll mod = 1e9 + 7;

ll adderlong(ll x, ll y)
{
    return (mod + (x % mod) + (y % mod)) % mod;
}
ll mlerlong(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
ll powlong(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll pw = powlong(x, y / 2);
    pw = mlerlong(pw, pw);
    if (y % 2 == 1)
        return mlerlong(pw, x);
    return pw;
}
ll minv(ll x)
{
    return powlong(x, mod - 2);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll s1 = 0;
    ll s2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        s1 = adderlong(s1, v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s2 = adderlong(s2, mlerlong(s1 - v[i], v[i]));
    }
    ll ans = mlerlong(s2, minv(mlerlong(n, n - 1)));
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