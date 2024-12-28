#include <bits/stdc++.h>

using i64 = long long;
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
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
    }

    const int N = n * m;
    DSU dsu(N);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n && s[i][j] == '#' && s[i + 1][j] == '#')
            {
                dsu.merge(i * m + j, (i + 1) * m + j);
            }
            if (j + 1 < m && s[i][j] == '#' && s[i][j + 1] == '#')
            {
                dsu.merge(i * m + j, i * m + j + 1);
            }
        }
    }

    std::vector<int> vis(N, -1);
    int ans = 0;
    for (int r = 0; r < n; r++)
    {
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            if (s[r][i] == '.')
            {
                res++;
            }
            for (int x = std::max(0, r - 1); x <= std::min(n - 1, r + 1); x++)
            {
                if (s[x][i] == '#')
                {
                    int u = dsu.find(x * m + i);
                    if (vis[u] != r)
                    {
                        vis[u] = r;
                        res += dsu.size(u);
                    }
                }
            }
        }
        ans = std::max(ans, res);
    }
    vis.assign(N, -1);
    for (int c = 0; c < m; c++)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i][c] == '.')
            {
                res++;
            }
            for (int y = std::max(0, c - 1); y <= std::min(m - 1, c + 1); y++)
            {
                if (s[i][y] == '#')
                {
                    int u = dsu.find(i * m + y);
                    if (vis[u] != c)
                    {
                        vis[u] = c;
                        res += dsu.size(u);
                    }
                }
            }
        }
        ans = std::max(ans, res);
    }

    std::cout << ans << "\n";
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