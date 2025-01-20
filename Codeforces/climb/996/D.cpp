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
    ll n, m;
    vector<pair<int, int>> path;
    path.push_back({0, 0});
    int curR = 0, curC = 0;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<bool>> op(n, vector<bool>(m, false));
    vector<ll> b(n + m, 0);
    vector<bool> ue(n + m - 1, false);
    vector<ll> ev(n + m - 1, 0);
    queue<int> q;
    vector<bool> inq(n + m, false), rm(n + m, false);

    string s;
    cin >> s;
    for (int i = 0; i < n + m - 2; i++)
    {
        char c = s[i];
        (c == 'R') ? curC++ : curR++;
        path.push_back({curR, curC});
    }

    for (auto &p : path)
        op[p.first][p.second] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<ll> fr(n, 0), fc(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!op[i][j])
            {
                fr[i] += a[i][j];
                fc[j] += a[i][j];
            }
    for (int i = 0; i < n; i++)
        b[i] = -fr[i];
    for (int i = 0; i < m; i++)
        b[n + i] = -fc[i];
    vector<vector<pair<int, int>>> adj(n + m);
    for (int i = 0; i < n + m - 1; i++)
    {
        pair<int, int> pr = path[i];
        int u = pr.first, v = n + pr.second;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> deg(n + m, 0);
    for (int i = 0; i < n + m; i++)
        deg[i] = adj[i].size();
    for (int i = 0; i < n + m; i++)
        if (deg[i] == 1)
        {
            q.push(i);
            inq[i] = true;
        }

    auto bfs = [&]()
    {
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (rm[u] || deg[u] == 0)
                continue;
            int nei = -1, eid = -1;
            for (auto &p : adj[u])
            {
                if (!ue[p.second])
                {
                    nei = p.first;
                    eid = p.second;
                    break;
                }
            }
            if (eid == -1)
                continue;
            ev[eid] = b[u];
            ue[eid] = 1;
            rm[u] = 1;
            deg[u]--;
            deg[nei]--;
            b[nei] -= ev[eid];
            if (deg[nei] == 1 && !rm[nei] && !inq[nei])
            {
                q.push(nei);
                inq[nei] = 1;
            }
        }
    };
    bfs();
    for (int i = 0; i < n + m - 1; i++)
    {
        pair<int, int> zx = path[i];
        a[zx.first][zx.second] = ev[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
