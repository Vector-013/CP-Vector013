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
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    q.push(0);
    vector<int> vis(n, -1);
    vector<int> d(n, inf);
    vis[0] = 0;
    d[0] = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto y : g[x])
        {
            if (vis[y] == -1)
            {
                vis[y] = x;
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    if (vis[n - 1] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int x = n - 1;
    while (x != 0)
    {
        path.push_back(x);
        x = vis[x];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (auto x : path)
        cout << x + 1 << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}