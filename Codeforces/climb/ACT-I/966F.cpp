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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    int q, w;
    for (int i = 0; i < n; i++)
    {
        cin >> q >> w;
        a[i] = {min(q, w), max(q, w)};
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));

    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i].first;
        int y = a[i].second;
        int t = x + y;
        int g = 0;
        for (int j = 0; j <= t; j++)
        {
            for (int l = 0; l + j <= k; l++)
            {
                dp[i + 1][l + j] = min(dp[i + 1][l + j], dp[i][l] + g);
            }
            if (x >= y)
            {
                g += y;
                x--;
            }
            else
            {
                g += x;
                y--;
            }
        }
    }
    cout << (dp[n][k] == inf ? -1 : dp[n][k]) << '\n';
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