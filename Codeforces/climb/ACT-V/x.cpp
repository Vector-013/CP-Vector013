#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<i64> f(n, inf), g(n, inf);
    std::vector<int> r(n);
    auto dfs = [&](auto self, int x, int p) -> void
    {
        int d = 0;
        for (auto y : adj[x])
        {
            if (y == p)
            {
                continue;
            }
            d++;
            self(self, y, x);
        }

        std::vector<i64> val(d + 2);
        i64 sum = 0;
        for (auto y : adj[x])
        {
            if (y == p)
            {
                continue;
            }
            sum += f[y];
            if (r[y] < d + 2)
            {
                val[r[y]] += g[y] - f[y];
            }
        }
        for (int i = 0; i < d + 2; i++)
        {
            i64 res = sum + val[i] + (i + 1) * a[x];
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

    std::cout << f[0] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}