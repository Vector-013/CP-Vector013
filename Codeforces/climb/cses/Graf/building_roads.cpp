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
    vector<vector<int>> g(n);
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        dsu.merge(x, y);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[dsu.find(i)])
        {
            vis[dsu.find(i)] = true;
            pq.push({dsu.size(i), dsu.find(i)});
        }
    }
    vector<pair<int, int>> ans;
    while (pq.size() > 1)
    {
        auto [s, u] = pq.top();
        pq.pop();
        auto [t, v] = pq.top();
        pq.pop();
        dsu.merge(u, v);
        ans.push_back({u, v});
        pq.push({dsu.size(u), dsu.find(u)});
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
    {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}