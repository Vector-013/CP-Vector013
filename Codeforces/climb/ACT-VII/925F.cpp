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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> d(n, 0);
    for (int i = 0; i < k; ++i)
    {
        int z, l;
        if (n > 1)
            cin >> z >> l;
        else
        {
            cin >> z;
            cout << "YES\n";
            return;
        }
        z--, l--;
        for (int j = 0; j < n - 2; j++)
        {
            int x;
            cin >> x;
            x--;
            g[l].push_back(x);
            l = x;
            d[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (!d[i])
            q.push(i);
    vector<int> vis(n, 0);
    int cnt = 0;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        cnt++;
        // cout << "u :" << u << " \n";
        if (vis[u])
        {
            cout << "NO\n";
            return;
        }
        vis[u] = 1;
        for (auto v : g[u])
        {
            d[v]--;
            if (!d[v])
                q.push(v);
        }
    }
    cout << ((cnt == n) ? "YES\n" : "NO\n");
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
