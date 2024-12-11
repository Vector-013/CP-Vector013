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
    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> d(n + 1), a(n + 1);
    vector<vector<ll>> dp(n + 2, vector<ll>(k + 1, inf));
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0ll;
    d.push_back(l);

    for (int i = 1; i <= n + 1; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; ++j)
        {

            if (i < j)
                continue;
            for (int p = i + 1; p <= n + 1; p++)
            {
                if (j + p - i - 1 > k)
                    break;
                dp[p][j + p - i - 1] = min(dp[p][j + p - i - 1], dp[i][j] + a[i] * (d[p] - d[i]));
            }
        }
    }
    cout << *min_element(dp[n + 1].begin(), dp[n + 1].end()) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}