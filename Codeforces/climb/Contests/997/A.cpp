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
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    if (n == 1)
    {
        cout << 4ll * m << '\n';
        return;
    }
    ll ans = 4ll * m;
    int bx = x[0], by = y[0];
    int tx = m + x[0], ty = m + y[0];
    for (int i = 1; i < n; i++)
    {
        bx += x[i], by += y[i];
        ans += (4ll * m - 2ll * (tx - bx) - 2ll * (ty - by));
        tx = bx + m, ty = by + m;
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