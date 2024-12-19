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
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n, 0);
    vector<int> deep(n, 0);
    map<int, multiset<int>> ppl;
    vector<int> who(n);

    auto dfs1 = [&](auto self, int u, int p) -> void
    {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            d[v] = d[u] + 1;
            self(self, v, u);
            ppl[u].insert(deep[v]);
            if (deep[v] + 1 >= deep[u])
            {
                deep[u] = deep[v] + 1;
                who[u] = v;
            }
        }
    };
    dfs1(dfs1, 0, -1);
    for (int i = 0; i < n; ++i)
    {
        cout << deep[i] << " ";
    }
    cout << '\n';
    vector<int> depest(n, 0);
    auto dfs2 = [&](auto self, int u, int p) -> void
    {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (who[u] == v)
            {
                auto it = ppl[u].end();
                if (ppl[u].size() > 1)
                {
                    it--;
                    it--;
                    if (*it + 2 > deep[v])
                    {
                        depest[v] = *it + 2;
                        who[v] = u;
                    }
                    else
                        depest[v] = deep[v];
                }
                else
                    depest[v] = deep[v];
            }
            else
            {
                depest[v] = depest[u] + 1;
                who[v] = u;
            }
            self(self, v, u);
        }
    };
    depest[0] = deep[0];
    dfs2(dfs2, 0, -1);
    for (int i = 0; i < n; ++i)
    {
        cout << depest[i] << " ";
    }
    cout << '\n';
    ll ans = -linf;
    for (int i = 0; i < n; i++)
        ans = max(ans, -1LL * d[i] * c + 1LL * k * depest[i]);
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