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
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 5, vector<int>(5, 0));
    char c;
    int cnt = 0;
    dp[0][0] = dp[0][2] = 1;
    dp[0][1] = 0;
    dp[0][3] = 1;
    dp[0][4] = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (c == '+')
        {
            cnt++;
            int x, a;
            cin >> x >> a;
            x--;
            dp[cnt][2] = dp[x][2] + a;
            dp[cnt][3] = max(dp[cnt][2], dp[x][3]);
            dp[cnt][4] = min(dp[cnt][2], dp[x][4]);
            dp[cnt][0] = max(dp[cnt][2] - dp[cnt][4], dp[x][0]);
            dp[cnt][1] = min(dp[cnt][2] - dp[cnt][3], dp[x][1]);
        }
        else
        {
            int x, y, z;
            cin >> x >> y >> z;
            y--;
            if (z >= dp[y][1] && z <= dp[y][0])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
