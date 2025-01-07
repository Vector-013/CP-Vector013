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
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    if (a == b)
    {
        cout << "NO\n";
        return;
    }
    vector<int> vis(n, 0);
    int start = -1;
    int end = -1;
    vector<int> parent(n, -1);

    auto dfs = [&](auto &self, int u, int p) -> void
    {
        if (u == start)
            return;
        parent[u] = p;
        if (vis[u] == 1)
        {
            if (start == -1)
                start = p;
        }
        vis[u] = 1;

        for (int v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
        }
    };

    dfs(dfs, 0, -1);

    vector<int> mrk(n, 0);
    vector<int> cycle;
    int pp = parent[start];
    mrk[start] = 1;
    cycle.push_back(start);
    while (pp != start)
    {
        cycle.push_back(pp);
        mrk[pp] = 1;
        pp = parent[pp];
    }

    queue<int> q;

    int cb = b;
    vector<int> dist(n);
    int dcb = -1;
    int clstb = -1;
    dist.assign(n, -1);
    dist[b] = 0;
    q.push(b);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (mrk[u])
        {
            dcb = dist[u];
            clstb = u;
            break;
        }
        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    while (!q.empty())
        q.pop();
    int ca = a;
    vector<int> dista(n);
    int dca = -1;
    int clsta = -1;
    dista.assign(n, -1);
    dista[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == clstb)
        {
            dca = dista[u];
            break;
        }
        for (int v : g[u])
        {
            if (dista[v] == -1)
            {
                dista[v] = dista[u] + 1;
                q.push(v);
            }
        }
    }

    if (dca > dcb)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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