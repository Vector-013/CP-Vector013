#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
auto mex = [](set<int> &s) -> int
{
    int mex = 0;
    while (s.count(mex))
        mex++;
    return mex;
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }

    vector<vector<bool>> dp(n, vector<bool>(n + 1));
    ll ans = 0;
    auto dfs = [&](auto &self, int u) -> int
    {
        int l = 0;
        dp[u][0] = true;
        for (int v : g[u])
        {
            int r = self(self, v);
            for (int i = l; i >= 0; i--)
                if (dp[u][i])
                {
                    dp[u][i + r] = true;
                }
            l += r;
        }
        ll now = 0;
        for (int i = l; i >= 0; i--)
            if (dp[u][i])
            {
                dp[u][i + 1] = true;
                dp[u][i] = false;
                now = max(now, (ll)i * (l - i));
            }
        ans += now;
        return l + 1;
    };
    dfs(dfs, 0);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

        solve();
}