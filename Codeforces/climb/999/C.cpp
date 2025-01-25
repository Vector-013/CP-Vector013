#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    auto modadd = [&](ll a, ll b) -> ll
    {
        a += b;
        a %= mod;
        return a;
    };
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            dp[i] = modadd(dp[i], dp[i - 1]);
        if (i > 1 && a[i] == a[i - 2] + 1)
            dp[i] = modadd(dp[i], dp[i - 2]);
    }

    cout << modadd(dp[n], dp[n - 1]) << '\n';
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