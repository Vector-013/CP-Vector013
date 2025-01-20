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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    ll ans = 0, gg = 0, ff = 0;
    vector<vector<int>> g(n);
    vector<vector<int>> f(n);
    vector<int> z(n, -1);
    vector<bool> vis(n, false), vis2(n, false);
    for (int i = 0; i < m1; i++)
    {
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        f[x].push_back(y);
        f[y].push_back(x);
    }
    for (int i = 0; i < m2; i++)
    {
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    auto dfs1 = [&](auto &self, int u, int p) -> void
    {
        vis[u] = true;
        z[u] = p;
        for (auto v : g[u])
        {
            if (!vis[v])
                self(self, v, p);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(dfs1, i, i);
            gg++;
        }
    }

    auto dfs2 = [&](auto &self, int u) -> void
    {
        vis2[u] = true;
        for (auto v : f[u])
        {
            if (!vis2[v])
            {
                if (z[v] == z[u])
                    self(self, v);
                else
                    ans++;
            }
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!vis2[i])
        {
            ff++;
            dfs2(dfs2, i);
        }
    }
    cout << ans + ff - gg << '\n';
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