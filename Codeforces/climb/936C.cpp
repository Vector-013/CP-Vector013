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
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto check = [&](int x)
    {
        int cnt = 0;
        map<int, int> mp;

        auto dfs = [&](auto self, int u, int p) -> void
        {
            int sub = 1;
            for (int v : g[u])
            {
                if (v == p)
                    continue;
                self(self, v, u);
                sub += mp[v];
            }
            mp[u] = sub;
            if (sub >= x)
            {
                cnt++;
                mp[u] = 0;
            }
        };
        dfs(dfs, 0, -1);
        return cnt > k;
    };

    int l = 0, r = n - 1;

    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }
    cout << l << '\n';
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