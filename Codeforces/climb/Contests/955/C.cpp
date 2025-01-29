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
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> dp(n + 1);
    dp[0] = 0;
    int cur = 0;
    ll sum =0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        while ((sum - a[cur]) >= l)
            sum -= a[cur++];
        dp[i + 1] = max(dp[i], dp[cur] + (sum >= l && sum <= r));
    }
    cout << dp[n] << '\n';
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