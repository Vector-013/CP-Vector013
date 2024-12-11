#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const ll mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<ll> dp1(n + 2), dp2(n + 2);
    dp1[0] = 1;
    auto modadd = [&](ll &a, ll b)
    {
        a += b;
        if (a >= mod)
            a -= mod;
        return a;
    };

    while (n--)
    {
        int v;
        cin >> v;

        dp1[v + 1] = modadd(dp1[v + 1], dp1[v + 1]);
        dp1[v + 1] = modadd(dp1[v + 1], dp1[v]);
        if (v > 0)
            dp2[v - 1] = modadd(dp2[v - 1], dp2[v - 1]);
        if (v > 0)
            dp2[v - 1] = modadd(dp2[v - 1], dp1[v - 1]);
        dp2[v + 1] = modadd(dp2[v + 1], dp2[v + 1]);
    }
    ll ans = 0;
    for (auto a : dp1)
    {
        ans = modadd(ans, a);
    }
    for (auto a : dp2)
    {
        ans = modadd(ans, a);
    }
    cout << modadd(ans, mod - 1) << '\n';
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