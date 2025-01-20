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

    vector<int> cycle;
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);
    auto dfs = [&](auto self, int u, int p) -> void
    {
        vis[u] = 1;
        parent[u] = p;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (vis[v] == 0)
            {
                self(self, v, u);
            }
            else if (vis[v] == 1 && cycle.empty())
            {
                for (int x = u; x != v; x = parent[x])
                {
                    cycle.push_back(x);
                }
                cycle.push_back(v);
            }
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(dfs, i, -1);
            if (!cycle.empty())
                break;
        }
    }
    if (cycle.empty())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cycle.push_back(cycle[0]);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << "\n";
    for (auto x : cycle)
        cout << x + 1 << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}