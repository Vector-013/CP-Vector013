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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> comp(n, -1);
    int cnt = 0;
    auto dfs = [&](auto &self, int u) -> void
    {
        comp[u] = cnt;
        for (int v : g[u])
        {
            if (comp[v] == -1)
                self(self, v);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (comp[i] == -1)
        {
            dfs(dfs, i);
            cnt++;
        }
    }
    vector<vector<int>> graphs(cnt);
    for (int i = 0; i < n; i++)
        graphs[comp[i]].push_back(i);

    vector<int> color(n, -1);

    auto bipartite = [&](auto &gg) -> bool
    {
        auto dfs = [&](auto &self, int u, int c) -> bool
        {
            color[u] = c;
            for (auto v : g[u])
            {
                if (color[v] == -1)
                {
                    if (!self(self, v, c ^ 1))
                        return false;
                }
                else if (color[v] == c)
                    return false;
            }
            return true;
        };
        int start = gg[0];
        if (!dfs(dfs, start, 0))
            return false;
        return true;
    };

    for (auto &graf : graphs)
    {
        if (!bipartite(graf))
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
        cout << color[i] + 1 << " \n"[i == n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}