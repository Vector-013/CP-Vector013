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
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<ll> vis(n * n, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0ll, 0ll);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u] != -1)
            continue;

        vis[u] = d;
        ll x = u / n, y = u % n;
        if (x == n - 1)
        {
            cout << vis[u] << '\n';
            return;
        }
        pq.emplace(d, x * (n + 1));
        for (auto [v, w] : g[x])
            pq.emplace(d + w * b[y], n * v + y);
    }
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
