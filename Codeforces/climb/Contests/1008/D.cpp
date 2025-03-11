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
    long long dp[31][2];
    int op[30][2];
    long long w[30][2];
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "+")
            op[i][0] = 0;
        else
            op[i][0] = 1;
        cin >> w[i][0];
        cin >> s;
        if (s == "+")
            op[i][1] = 0;
        else
            op[i][1] = 1;
        cin >> w[i][1];
    }
    dp[n][0] = 1;
    dp[n][1] = 1;
    int x;
    for (int i = n - 1; i > -1; i--)
    {
        if (op[i][0])
            x = w[i][0] - 1;
        else
            x = 0;
        dp[i][0] = dp[i + 1][0] + x * max(dp[i + 1][0], dp[i + 1][1]);
        if (op[i][1])
            x = w[i][1] - 1;
        else
            x = 0;
        dp[i][1] = dp[i + 1][1] + x * max(dp[i + 1][0], dp[i + 1][1]);
    }
    ll ans = dp[0][0] + dp[0][1];
    for (int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " " << dp[i][1] << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        x = 0;
        if (op[i][0] == 0)
            x += w[i][0];
        if (op[i][1] == 0)
            x += w[i][1];
        ans += x * max(dp[i + 1][0], dp[i + 1][1]);
    }
    cout << ans << '\n';
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