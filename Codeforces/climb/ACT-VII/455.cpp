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
    vector<char> c(n+1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    if (c[n] == 'f')
    {
        cout << "0\n";
        return;
    }
    int cntf = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, 0ll));
    for (int i = 0; i <= n+1; i++)
        dp[n][i] = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        int sum = 0;
        for (int l = 0; l <= n; l++)
        {

            sum += dp[i + 1][l];
            sum %= mod;

            if (c[i] == 'f')
            {
                dp[i][l] = dp[i + 1][l + 1];
            }
            else
            {
                dp[i][l] = sum;
            }
        }
    }

    cout << dp[1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
