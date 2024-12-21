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
    vector<bool> mrk(n);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        mrk[x - 1] = true;
    }
    auto mrk2 = mrk;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> deep(n, 0);
    vector<ll> who(n);
    map<ll, multiset<ll>> mp, exist;

    auto dfs1 = [&](auto self, int u, int p) -> void
    {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            if (mrk2[v])
            {

                mp[u].insert(deep[v] + 1);
                if (deep[v] + 1 >= deep[u])
                {
                    deep[u] = deep[v] + 1;
                    who[u] = v;
                }

                if (exist[u].size() > 0 || mrk[u] == true)
                {
                    if (exist[u].size() == 1)
                    {
                        int x = *exist[u].begin();
                        exist[x].insert(u);
                    }
                    exist[v].insert(u);
                }
                mrk2[u] = true;
                exist[u].insert(v);
            }
        }
    };
    dfs1(dfs1, 0, -1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << deep[i] << ' ';
    // }
    // cout << '\n';

    vector<int> depest(n, 0);
    auto dfs2 = [&](auto self, int u, int p, ll dup) -> void
    {
        if (p != -1 && exist[p].count(u) && exist[p].size() == 1)
        {
            dup = 0;
        }

        depest[u] = max(deep[u], dup);
        ll max1 = 0, max2 = 0;
        if (mp[u].size() != 0)
        {
            auto it = mp[u].rbegin();
            it--;
            max1 = *it;
            if (mp[u].size() > 1)
            {
                it--;
                max2 = *it;
            }
        }
        // cout << "v: " << u << " max1: " << max1 << " max2: " << max2 << " dup: " << dup << '\n';

        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (who[u] == v)
            {
                self(self, v, u, max(max2 + 1, dup + 1));
            }
            else
            {
                self(self, v, u, max(max1 + 1, dup + 1));
            }
        }
    };
    depest[0] = deep[0];
    dfs2(dfs2, 0, -1, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << depest[i] << ' ';
    // }
    // cout << '\n';
    ll ans = *min_element(depest.begin(), depest.end());
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