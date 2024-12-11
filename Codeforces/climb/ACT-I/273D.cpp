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
    int r, g;
    cin >> r >> g;
    int h;
    vector<int> dp(r + g + 1, 0);
    dp[0] = 1;
    for (h = 1; h * (h + 1) / 2 <= r + g; h++)
    {
        for (int i = r + g; i >= h; i--)
        {
            dp[i] = (dp[i] + dp[i - h]) % mod;
        }
    }
    int ans = 0;
    h--;
    for (int i = 0; i <= r; i++)
    {
        if (g + i >= h * (h + 1) / 2)
        {
            ans = (ans + dp[i]) % mod;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}