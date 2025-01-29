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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    x = s - x;
    y = s - y;
    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int j1 = upper_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin() - 1;
        if ((a[j1] + a[i] > x))
            continue;

        int j2 = lower_bound(a.begin() + i + 1, a.end(), y - a[i]) - a.begin();
        if ((a[j2] + a[i] < y))
            continue;
        if (j2 <= j1)
            ans += j1 - j2 + 1;
    }
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