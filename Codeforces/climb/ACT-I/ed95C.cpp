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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, inf));
    dp[0][1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int st = 1; st <= min(2, n - i); st++)
            {
                int x = a[i] + (st > 1 ? a[i + 1] : 0);
                dp[i + st][j ^ 1] = min(dp[i + st][j ^ 1], dp[i][j] + x * j);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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