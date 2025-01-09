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
    vector<vector<int>> g(n, vector<int>());
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    vector<int> lvl(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            q.push(i);
            lvl[i] = 1;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            deg[v]--;
            if (deg[v] == 1)
            {
                q.push(v);
                lvl[v] = lvl[u] + 1;
            }
        }
    }
    sort(lvl.begin(), lvl.end());
    int loc = upper_bound(lvl.begin(), lvl.end(), k) - lvl.begin();
    cout << n - loc << '\n';
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