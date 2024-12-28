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
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> vis(n, 0), cnt(n, 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
            pq.push({1, i});
    }
    int m;
    int curr = 0;

    while (!pq.empty())
    {
        auto [ppl, u] = pq.top();
        pq.pop();
        for (auto &v : g[u])
        {
            if (vis[v])
                continue;
            m = v;
            break;
        }
        if (cnt[u] <= cnt[m])
        {
            vis[u] = 1;
            cnt[m] += cnt[u];
            curr++;
            deg[m]--;
            if (deg[m] == 1)
            {
                pq.push({cnt[m], m});
            }
            if (curr == n - 1)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}