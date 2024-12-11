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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), pre(n + 1), dp(n + 1, linf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int maxa = *max_element(a.begin(), a.end());
    if (maxa > b[0])
    {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int k = 0; k < m; k++)
    {
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (pre[i] - pre[j] > b[k])
            {
                j++;
            }
            dp[i] = min(dp[i], dp[j] + m - k - 1);
        }
    }
    cout << dp[n] << "\n";
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