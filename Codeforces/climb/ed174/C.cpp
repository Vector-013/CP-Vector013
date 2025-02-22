#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 998244353;

ll modadd(ll a, ll b, ll mod)
{
    return ((a % mod) + (b % mod)) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> dp(4, 0ll);
    dp[0] = 1ll;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 2)
            dp[a[i]] = modadd(dp[a[i]], dp[a[i]], mod);
        dp[a[i]] = modadd(dp[a[i]], dp[a[i] - 1], mod);
    }
    cout << dp[3] << '\n';
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
