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
    ll ans = linf, c;
    ll n;
    cin >> n;
    vector<ll> a(n + 1), l(n + 1), r(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        l[i] = a[i] + i;
        r[i] = a[i] + n - i - 1;
    }
    for (int i = 1; i < n; i++)
        r[i] = max(r[i], r[i - 1]);
    for (int i = n - 2; i > -1; i--)
        l[i] = max(l[i], l[i + 1]);
    for (int i = 0; i < n; i++)
    {
        c = a[i];
        if (i > 0)
            c = max(c, r[i - 1]);
        if (i < n - 1)
            c = max(c, l[i + 1]);
        ans = min(ans, c);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}