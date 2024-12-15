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
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        g[i].push_back({x, y});
        g[x].push_back({i, y});
    }
    vector<ll> d(n);
    d[0] = 0;
    ll ans = 0;
    vector<ll> subtre(n);
    auto dfs1 = [&](auto self, int u, int p) -> void
    {
        subtre[u] = 1;
        for (auto [v, w] : g[u])
        {
            if (v == p)
                continue;
            d[v] = d[u] + w;
            self(self, v, u);
            subtre[u] += subtre[v];
        }
    };
    dfs1(dfs1, 0, -1);
    vector<ll> minabove(n);
    auto dfs2 = [&](auto self, int u, int p) -> void
    {
        for (auto [v, w] : g[u])
        {
            if (v == p)
                continue;
            minabove[v] = min(minabove[u], d[v]);
            if ((d[v] - a[v] > minabove[v]) || (u == 0 && d[v] - a[v] > 0))
                ans += subtre[v];
            else
                self(self, v, u);
        }
    };
    minabove[0] = 0;
    dfs2(dfs2, 0, -1);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}