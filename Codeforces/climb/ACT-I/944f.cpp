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
    ll d;
    ll ans = 0;
    cin >> d;
    auto dist = [&](ll x, ll y) -> ld
    {
        return sqrtl(x * x + y * y);
    };
    ll h = d;
    for (ll i = 0; i <= d; i++)
    {
        while (i * i + h * h >= (d + 1) * (d + 1))
        {
            h--;
        }
        ll hn = h;
        while ((i * i + hn * hn >= d * d) && hn > 0)
        {
            ans++;
            hn--;
        }
    }
    ans <<= 2;
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