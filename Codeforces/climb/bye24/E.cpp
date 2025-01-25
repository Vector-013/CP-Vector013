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
    vector<vector<int>> g(n);
    vector<int> d(n, 2);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 2)
    {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            d[i] = 0;
            d[g[i][0]] = 1;
        }
    }
    ll ans = 0;
    int cnt1 = count(d.begin(), d.end(), 1);
    int cnt2 = count(d.begin(), d.end(), 2);
    vector<int> siz2(n), siz1(n);

    auto dfs = [&](auto &self, int u, int p) -> void
    {
        siz1[u] = (d[u] == 1);
        siz2[u] = (d[u] == 2);
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            siz1[u] += siz1[v];
            siz2[u] += siz2[v];
            if (d[u] == 0)
                ans += siz1[v] + siz2[v];
            else if (d[v] == 1)
                ans += siz2[v];
            if (d[v] == 0)
                ans += cnt2 + cnt1;
            else if (d[u] == 1)
                ans += cnt2 - siz2[v];
        }
    };
    dfs(dfs, 0, -1);
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