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
    vector<vector<int>> g(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt[x]++;
        cnt[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (auto [z, w] : cnt)
    {
        if (w != 2)
        {
            cout << "NO\n";
            return;
        }
    }
    vector<bool> vis(n, false);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            cur = 1;
            int node = g[i][0];
            int p = i;
            while (node != i && !vis[node])
            {
                vis[node] = true;
                cur++;
                auto tmp = node;
                node = ((g[node][0] == p) ? g[node][1] : g[node][0]);
                p = tmp;
            }
            if (cur & 1)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
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