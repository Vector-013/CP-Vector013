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
    ll n, k;
    cin >> n >> k;
    ll q = 0;
    ld v = (ld)(n + 1) / 2;
    ll l = n / 2, x = 1, z = 0;
    while (l >= k)
    {
        q = (l & 1) ? q + (1 << x) : q;
        l /= 2;
        x++;
    }
    ll ans;
    ans = (n + 1) * q / 2;
    ans = (n & 1) ? ans + (n + 1) / 2 : ans;
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