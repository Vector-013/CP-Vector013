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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    int x, y;
    cin >> x >> y;
    x--, y--;
    vector<bool> mrk(n, 0);
    for (int i = 0; i < k; i++)
    {
        int z;
        cin >> z;
        z--;
        mrk[z] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> hasy(n, false);
    vector<bool> hasmrk(n, false);
    auto dfs1 = [&](auto self, int u, int p) -> void
    {
        if (u == y)
            hasy[u] = true;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            hasy[u] = hasy[u] || hasy[v];
            if (mrk[u] || hasmrk[v])
                hasmrk[u] = true;
        }
        if (mrk[u])
            hasmrk[u] = 1;
    };

    dfs1(dfs1, x, -1);
    int ans = 0;

    auto dfs2 = [&](auto self, int u, int p) -> void
    {
        ans++;
        int last = -1;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (hasy[v])
            {
                last = v;
                break;
            }
        }
        for (auto v : g[u])
        {
            if (v == p || v == last)
                continue;
            if (hasmrk[v])
            {
                self(self, v, u);
            }
        }
        if (last != -1)
            self(self, last, u);
        if (u == y)
        {
            cout << ans - 1 << '\n';
        }
        ans++;
    };
    dfs2(dfs2, x, -1);
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