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
    vector<ll> a(n), f(n, linf), g(n, linf), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto self, int x, int p) -> void
    {
        ll d = 0ll;
        for (auto y : adj[x])
        {
            if (y == p)
                continue;
            d++;
            self(self, y, x);
        }
        vector<ll> val(d + 2);
        ll sum = 0;
        for (auto y : adj[x])
        {
            if (y == p)
                continue;
            sum += f[y];
            if (r[y] < d + 2)
                val[r[y]] += g[y] - f[y];
        }
        for (int i = 0; i < d + 2; i++)
        {
            ll res = sum + val[i] + (i + 1) * a[x];
            if (res < f[x])
            {
                g[x] = f[x];
                f[x] = res;
                r[x] = i;
            }
            else if (res < g[x])
            {
                g[x] = res;
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << f[0] << '\n';
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