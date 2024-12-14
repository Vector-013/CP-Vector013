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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> scr(n), depth(n, 1), sub(n, 1);
    auto dfs = [&](auto self, int u, int p) -> void
    {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
            sub[u] += sub[v];
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++)
        scr[i] = depth[i] - sub[i];
    sort(scr.begin(), scr.end(), greater<int>());
    cout << accumulate(scr.begin(), scr.begin() + k, 0ll) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}