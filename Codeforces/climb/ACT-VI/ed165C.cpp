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
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, linf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        ll cur = a[i];
        for (int j = 0; j + i < n; j++)
        {
            if (j > k)
                break;
            cur = min(cur, a[i + j]);
            for (int m = 0; m + j <= k; m++)
            {
                dp[i + j + 1][m + j] = min(dp[i + j + 1][m + j], dp[i][m] + cur * (j + 1) * 1ll + 0ll);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
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