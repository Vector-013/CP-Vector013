#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

struct DSU
{
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());
    DSU dsu(n);
    tuple<int, int, int> last;
    vector<vector<int>> adj(n);
    for (auto [w, u, v] : edges)
    {
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
            last = {w, u, v};
    }
    int start = get<1>(last), end = get<2>(last);
    cout << get<0>(last) << ' ';
    vector<int> path;
    auto dfs = [&](auto &self, int u, int p, int e) -> void
    {
        if (u == e)
        {
            path.push_back(u);
            return;
        }
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u, e);
            if (!path.empty())
            {
                path.push_back(u);
                return;
            }
        }
    };
    dfs(dfs, start, -1, end);
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); i++)
        cout << path[i] + 1 << ' ';
    cout << '\n';
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