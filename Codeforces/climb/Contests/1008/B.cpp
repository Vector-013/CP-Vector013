#include <bits/stdc++.h>
using namespace std;
long long dp[31][2];
int op[30][2];
long long w[30][2];
string s;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T, n, i, x;
    long long ans;
    for (cin >> T; T > 0; T--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
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
        for (i = n - 1; i > -1; i--)
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
        ans = dp[0][0] + dp[0][1];
        for (i = 0; i < n; i++)
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
    return 0;
}