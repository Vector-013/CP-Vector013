
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
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;
    int q = n * m;
    DSU dsu(q);
    vector<int> vis(q, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
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
    int ans = 0;
    for (int z = 0; z < n; ++z)
    {
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            if (s[z][i] == '.')
                res++;
            for (int x = max(0, z - 1); x <= min(n - 1, z + 1); x++)
            {
                if (s[x][i] == '#')
                {
                    int p = dsu.find(x * m + i);
                    if (vis[p] != z)
                    {
                        vis[p] = z;
                        res += dsu.size(p);
                    }
                }
            }
        }
        ans = max(ans, res);
    }
    vis.assign(q, -1);
    for (int z = 0; z < m; ++z)
    {
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i][z] == '.')
                res++;
            for (int x = max(0, z - 1); x <= min(m - 1, z + 1); x++)
            {
                if (s[i][x] == '#')
                {
                    int p = dsu.find(i * m + x);
                    if (vis[p] != z)
                    {
                        vis[p] = z;
                        res += dsu.size(p);
                    }
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
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