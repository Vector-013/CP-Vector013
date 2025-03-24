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
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }
    vector<vector<int>> scc(n);
    stack<int> st;
    int timer = 0;
    vector<int> claimed(n, 0), dfs_order(n, -1), rep(n, -1), vis(n, 0);

    auto find_sccs = [&](auto &self, int u) -> void
    {
        vis[u] = 1;
        dfs_order[u] = timer++;
        st.push(u);
        rep[u] = dfs_order[u];

        for (auto v : g[u])
        {
            if (!vis[v])
                self(self, v);
            if (not claimed[v])
                rep[u] = min(rep[u], rep[v]);
        }

        if (rep[u] == dfs_order[u])
        {
            int popped = -1;
            while (popped != u)
            {
                popped = st.top();
                st.pop();
                claimed[popped] = 1;
                scc[u].push_back(popped);
            }
        }
        vis[u] = 2;
    };

    for (int i = 0; i < n; ++i)
        if (not vis[i])
            find_sccs(find_sccs, i);

    ll ans = 1ll, req = 0ll;

    for (auto v : scc)
    {
        if (not v.size())
            continue;
        vector<ll> cnt;
        for (auto u : v)
            cnt.push_back(a[u]);
        ll z = *min_element(cnt.begin(), cnt.end());
        req += z;
        ll c = count(cnt.begin(), cnt.end(), z);
        ans = (ans * c) % mod;
    }
    cout << req << " " << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}