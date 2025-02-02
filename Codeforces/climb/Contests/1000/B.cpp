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
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    l--, r--;
    vector<ll> x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < l)
            x.push_back(a[i]);
        else if (i > r)
            z.push_back(a[i]);
        else
            y.push_back(a[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end(), greater<ll>());
    sort(z.begin(), z.end());
    ll ans = accumulate(y.begin(), y.end(), 0LL);
    ll tmp = ans;
    int tt = min(x.size(), y.size());
    for (int i = 0; i < tt; i++)
    {
        if (x[i] < y[i])
            ans -= y[i] - x[i];
        else
            break;
    }
    tt = min(z.size(), y.size());
    for (int i = 0; i < tt; ++i)
    {
        if (y[i] > z[i])
            tmp -= y[i] - z[i];
        else
            break;
    }
    cout << min(ans, tmp) << '\n';
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