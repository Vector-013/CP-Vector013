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
    int n;
    cin >> n;
    vector<vector<int>> g(n), g2(n);
    vector<bool> vis(n);
    map<int, int> mp;
    ll ans = 2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        mp[x]++;
        g[x].push_back(i);
        g2[i].push_back(x);
    }
    vector<bool> cycle(n, false), leaf(n, false);
    for (int i = 0; i < n; i++)
    {
        if (mp[i] == 0)
            leaf[i] = true;
    }
    vector<bool> vis2(n, 0);
    auto mark = [&](auto &self, int u, stack<int> &st) -> void
    {
        for (auto v : g2[u])
        {
            cycle[u] = true;
            if (cycle[v])
                return;
            self(self, v, st);
        }
    };

    auto fincycle = [&](auto &self, int u, stack<int> &st) -> void
    {
        if (vis2[u] && !cycle[u])
            return;
        for (auto v : g2[u])
        {
            st.push(v);
            if (vis[v])
                return;
            if (vis2[v])
            {
                cycle[u] = true;
                mark(mark, u, st);
                return;
            }
            vis2[u] = true;
            self(self, v, st);
        }
    };
    for (int i = 0; i < n; i++)
    {
        stack<int> st;
        if (leaf[i] && !vis2[i])
        {
            fincycle(fincycle, i, st);
        }
        while (!st.empty())
        {
            auto x = st.top();
            st.pop();
            vis[x] = true;
        }
    }
    ll maxs = 0;

    vector<int> subtre(n, 0);

    auto dfs = [&](auto &self, int u, int bos) -> void
    {
        for (auto v : g[u])
        {
            if (cycle[v])
                continue;
            self(self, v, bos);
            if (u != bos)
                subtre[u] += subtre[v];
            else
                subtre[u] = max(subtre[u], subtre[v]);
        }
        subtre[u]++;
    };
    for (int i = 0; i < n; i++)
    {
        if (cycle[i])
        {
            subtre[i] = 0;
            dfs(dfs, i, i);
        }
    }
    maxs = *max_element(subtre.begin(), subtre.end());
    cout << max(maxs + 1, 2ll) << '\n';
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