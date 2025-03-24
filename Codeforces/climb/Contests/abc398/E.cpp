#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mp[{i, j}] = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }

    vector<int> vis(n, 0), col(n, -1);
    vector<int> b, w;

    auto color = [&](auto &self, int u, int c) -> void
    {
        vis[u] = 1;
        col[u] = c;
        for (auto v : g[u])
        {
            if (!vis[v])
                self(self, v, c ^ 1);
        }
    };

    color(color, 0, 0);
    for (int i = 0; i < n; ++i)
        (not col[i] ? b : w).push_back(i);

    for (int i = 0; i < w.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
        {
            if (mp[{w[i], b[j]}] != 1)
                mp[{w[i], b[j]}] = mp[{b[j], w[i]}] = 0;
        }
    int bla = count(col.begin(), col.end(), 0);
    int whi = n - bla;
    int tot = bla * whi - (n - 1);
    cout << ((tot & 1) ? "First" : "Second") << endl;
    cout.flush();

    auto give = [&]() -> pair<int, int>
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (not mp[{i, j}])
                {
                    mp[{i, j}] = mp[{j, i}] = 1;
                    return {i, j};
                }
        return {-1, -1};
    };
    if (tot & 1)
    {
        auto [u, v] = give();
        cout << u + 1 << ' ' << v + 1 << endl;
        cout.flush();
    }
    while (1)
    {
        int u, v;
        cin >> u >> v;

        if (u == -1)
            break;
        u--, v--;
        mp[{u, v}] = mp[{v, u}] = 1;
        auto [x, y] = give();
        cout << x + 1 << ' ' << y + 1 << endl;
        cout.flush();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}