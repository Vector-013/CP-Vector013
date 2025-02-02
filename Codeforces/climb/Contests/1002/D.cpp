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
    int n, s1, s2, m1, m2;
    cin >> n >> s1 >> s2 >> m1;
    s1--;
    s2--;
    vector<vector<int>> g1(n), g2(n);
    map<pair<int, int>, int> mp;
    vector<int> c;
    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
        if (mp[{u, v}] == 1)
            c.push_back(u), c.push_back(v);
    }
    if (!c.size())
    {
        cout << "-1\n";
        return;
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    dist[s1][s2] = 0;
    pq.push({0, {s1, s2}});
    while (!pq.empty())
    {
        auto d = -pq.top().first;
        auto [u, v] = pq.top().second;
        pq.pop();

        if (dist[u][v] < d)
            continue;

        dist[u][v] = d;
        for (auto x : g1[u])
            for (auto y : g2[v])
            {
                int nd = d + abs(y - x);
                if (dist[x][y] > nd)
                    dist[x][y] = nd, pq.push({-nd, {x, y}});
            }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i][i] < inf)
        {
            bool ok = 0;
            for (auto x : g1[i])
                for (auto y : g2[i])
                    if (x == y)
                        ok = 1;
            if (ok)
                ans = min(ans, dist[i][i]);
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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
