#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(3, vector<ll>(n, -linf));
    dp[0].assign(n, 0);
    ll ans = 0;
    dp[1][0] = 0;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }

        if (a[i] > dp[2][i])
            dp[2][i]++;
        else if (a[i] < dp[2][i])
            dp[2][i]--;
        if ((i > 0) && (a[i] > dp[0][i - 1]))
            dp[0][i] = dp[0][i - 1] + 1;
        else if ((i > 0) && (a[i] < dp[0][i - 1]))
        {
            dp[0][i] = dp[0][i - 1] - 1;

        }
        else if ((i > 0) && (a[i] == dp[0][i - 1]))
            dp[0][i] = dp[0][i - 1];

        // for (int j = 0; j < 3; j++)
        //     cout << dp[j][i] << " ";
        // cout << "\n";
    }

    cout << max(max(0ll, dp[1][n - 1]), dp[2][n - 1]) << '\n';
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