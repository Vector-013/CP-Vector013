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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 3 * (n / (a + b + c));
    ll d = (a + b + c) * (n / (a + b + c));
    vector<ll> v = {a, b, c};
    if (d >= n)
    {
        cout << ans << '\n';
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (d + v[i] >= n)
        {
            cout << ans + 1 << '\n';
            return;
        }
        ans++;
        d += v[i];
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