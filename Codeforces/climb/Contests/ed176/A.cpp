#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int mo, me;
    mo = (k & 1) ? k : k - 1;
    me = (k & 1) ? k - 1 : k;
    if (n & 1)
    {
        ans++;
        n -= mo;
        ans += (n + me - 1) / me;
    }
    else
        ans += (n + me - 1) / me;
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}