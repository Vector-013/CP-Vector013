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
    ll n, m;
    cin >> n >> m;
    map<pair<ll, ll>, int> mp;
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> graphset;
    bool basic = true;

    for (ll i = 0; i < m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (mp.find({x, y}) != mp.end())
        {
            if (mp[{x, y}] != d)
                basic = false;
        }
        if (mp.find({y, x}) != mp.end())
        {
            if (mp[{y, x}] != -d)
                basic = false;
        }
        mp[{x, y}] = d;
        mp[{y, x}] = -d;
    }
    if (!basic)
    {
        cout << "NO\n";
        return;
    }

    vector<bool> vis(n + 1ll, false);
    auto dfs1 = [&](ll u)
    {
        stack<ll> st;
        st.push(u);
        vis[u] = true;
        vector<ll> graph;
        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            graph.push_back(v);
            for (auto &x : adj[v])
            {
                if (!vis[x])
                {
                    vis[x] = true;
                    st.push(x);
                }
            }
        }
        graphset.push_back(graph);
    };
    auto add = [&]()
    {
        for (ll i = 1; i <= n; i++)
        {
            if (!adj[i].size())
                continue;
            if (!vis[i])
                dfs1(i);
        }
    };
    add();
    vis.assign(n + 1ll, false);

    auto graf_chk = [&](auto self, vector<ll> &g, ll u, ll p, map<ll, ll> &tmp) -> bool
    {
        vis[u] = true;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            if (vis[v])
            {
                if (tmp[v] - tmp[u] != mp[{u, v}])
                    return false;
                continue;
            }
            else
            {
                tmp[v] = tmp[u] + mp[{u, v}];
                if (!self(self, g, v, u, tmp))
                    return false;
            }
        }
        return true;
    };

    for (auto &g : graphset)
    {
        map<ll, ll> tmp;
        tmp[g[0]] = 0;
        if (!graf_chk(graf_chk, g, g[0], -1, tmp))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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