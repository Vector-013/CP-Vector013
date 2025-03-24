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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<vector<int>> g(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0ll; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<set<pair<int, int>>> s(n);
    vector<int> sz(n, 0ll), parent(n, -1ll), imp(n, 0ll);

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        sz[u] = 1ll;
        imp[u] = a[u];
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            imp[u] += imp[v];
            s[u].emplace(-sz[v], v);
            parent[v] = u;
        }
    };
    dfs(dfs, 0ll, -1);
    for (int i = 0ll; i < q; ++i)
    {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1ll)
        {
            cout << imp[x] << '\n';
        }
        else
        {
            int p = parent[x];
            if (s[x].empty())
                continue;
            auto [zz, son] = *s[x].begin();
            s[p].erase({-sz[x], x});
            s[x].erase(s[x].begin());
            sz[x] += zz;
            sz[son] += sz[x];
            s[son].emplace(-sz[x], x);
            s[p].emplace(-sz[son], son);
            imp[x] -= imp[son];
            imp[son] += imp[x];
            parent[son] = p;
            parent[x] = son;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}