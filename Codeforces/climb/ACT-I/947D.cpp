#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    cin >> n;
    int q, w;
    cin >> q >> w;
    q--;
    w--;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> path;
    auto dfs = [&](auto self, int v, int p) -> bool
    {
        if (v == w)
        {
            path.push_back(v);
            return true;
        }
        for (int u : g[v])
        {
            if (u == p)
                continue;
            if (self(self, u, v))
            {
                path.push_back(v);
                return true;
            }
        }
        return false;
    };
    dfs(dfs, q, -1);
    int root = path[path.size() / 2];
    ll ans = 0;
    ans += path.size() / 2;

    vector<int> deepest(n, 0);
    auto dfs2 = [&](auto self, int v, int p, int dpt) -> void
    {
        for (int u : g[v])
        {
            if (u == p)
                continue;
            self(self, u, v, dpt + 1);
            deepest[v] = max(deepest[v], deepest[u] + 1);
        }
    };
    dfs2(dfs2, root, -1, 0);
    sort(deepest.begin(), deepest.end(), greater<int>());
    ans += 2 * (n - 1) - deepest[0];
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