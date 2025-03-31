#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto &self, int u) -> void
    {
        vis[u] = true;
        for (auto v : g[u])
            if (not vis[v])
                self(self, v);
    };

    int x = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(dfs, i);
            x++;
        }
    }

    cout << m - n + x << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
