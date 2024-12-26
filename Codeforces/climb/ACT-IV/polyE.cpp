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
    int n, d;
    cin >> n >> d;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> q(n, -n), w(n, -n);
    int m1, m2;
    cin >> m1;
    for (int i = 0; i < m1; i++)
    {
        int x;
        cin >> x;
        x--;
        q[x] = 0;
    }
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        int x;
        cin >> x;
        x--;
        w[x] = 0;
    }
    auto dfs = [&](auto &self, int u, int p) -> void
    {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            q[u] = max(q[u], q[v] + 1);
            w[u] = max(w[u], w[v] + 1);
        }
        q[u] = max(q[u], w[u] - d);
        w[u] = max(w[u], q[u] - d);
    };
    dfs(dfs, 0, -1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (q[i] >= 0) + (w[i] >= 0);
    }
    cout << ans * 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}