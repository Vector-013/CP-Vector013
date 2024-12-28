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
    vector<pair<int, int>> c(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> c[i].first >> c[i].second >> r[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll dx = c[i].first - c[j].first;
            ll dy = c[i].second - c[j].second;
            if (1ll * dx * dx + 1ll * dy * dy <= 1ll * (r[i] + r[j]) * (r[i] + r[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> comp(n, -1);
    int cnt = 0;
    auto dfs = [&](auto &self, int u) -> void
    {
        comp[u] = cnt;
        for (int v : adj[u])
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

    auto bipartite = [&](auto &g) -> bool
    {
        vector<int> color(n, -1);
        auto dfs = [&](auto &self, int u, int c) -> bool
        {
            color[u] = c;
            for (auto v : adj[u])
            {
                if (color[v] == -1)
                {
                    if (!self(self, v, 1 - c))
                        return false;
                }
                else if (color[v] == c)
                    return false;
            }
            return true;
        };
        int start = g[0];
        if (!dfs(dfs, start, 0))
            return false;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
                cnt++;
            else if (color[i] == 1)
                cnt--;
        }
        return !(cnt == 0);
    };

    for (auto &g : graphs)
    {
        if (bipartite(g))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}