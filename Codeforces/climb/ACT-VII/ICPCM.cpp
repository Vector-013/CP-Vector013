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
    vector<vector<pair<ll, ll>>> g(2 * n);
    for (int i = 0; i < m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[2 * u].push_back({2 * v, w});
        g[2 * v + 1].push_back({2 * u + 1, w});
    }

    for (int i = 0; i < n; ++i)
        g[2 * i].push_back({2 * i + 1, 0ll});

    vector<ll> dist(2 * n, linf);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0ll, 0ll);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != linf)
            continue;
        dist[u] = d;

        for (auto [v, w] : g[u])
            pq.emplace(d + w, v);
    }

    for (int i = 1; i < n; ++i)
        cout << (dist[2 * i + 1] == linf ? -1 : dist[2 * i + 1]) << " \n"[i == n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
