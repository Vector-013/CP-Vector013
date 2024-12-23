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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<ll> dp1(n, 0ll), dp2(n, 0ll);

    auto dfs = [&](auto &self, int u, int p) -> void
    {
        dp1[u] = g[u].size();
        ll maxi1 = -linf, maxi2 = -linf;
        for (int v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            dp1[u] = max(dp1[u], dp1[v] + (ll)g[u].size() - 2ll);
            maxi2 = max(maxi2, dp1[v]);
            if (maxi2 > maxi1)
                swap(maxi1, maxi2);
        }
        dp2[u] = dp1[u];
        if ((g[u].size() > 2) || (p == -1 && g[u].size() > 1))
        {
            dp2[u] = max(dp2[u], maxi1 + maxi2 + (ll)g[u].size() - 4ll);
        }
    };
    dfs(dfs, 0, -1);
    cout << *max_element(dp2.begin(), dp2.end()) << '\n';
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