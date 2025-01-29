#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
map<ll, ll> dp;

ll maxcn(ll n)
{
    if (n <= 3)
    {
        return 1;
    }
    if (dp[n])
    {
        return dp[n];
    }
    ll s = n / 4;
    dp[n] = maxcn(s) + maxcn(s);
    return dp[n];
}

void solve()
{
    ll x;
    cin >> x;
    cout << maxcn(x) << '\n';
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