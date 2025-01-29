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
    ll x, y, k;
    cin >> x >> y >> k;

    while (k > 0 && x != 1)
    {
        ll cur = (x / y + 1) * y - x;
        cur = max(1ll, cur);
        cur = min(cur, k);
        x += cur;
        while (x % y == 0)
            x /= y;
        k -= cur;
    }
    cout << x + k % (y - 1) << '\n';
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