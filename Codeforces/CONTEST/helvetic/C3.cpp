#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<vector<int>> g(n);
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> s(n, 0);
    vector<int> stat(n, 0); // 1 => stone placer wins(all kids 0)
    vector<int> root_stat(n, 0);
    vector<int> parent(n);
    auto dfs1 = [&](auto &self, int u, int p) -> void
    {
        parent[u] = p;
        if (u != 0 && g[u].size() == 1)
        {
            stat[u] = 1;
            return;
        }
        for (auto v : g[u])
        {
            if (v != p)
                self(self, v, u);
        }
        stat[u] = 1;
        for (auto v : g[u])
        {
            if (v != p && stat[v])
            {
                stat[u] = 0;
                s[u]++;
            }
        }
    };
    dfs1(dfs1, 0, -1);
    for (int i = 1; i < n; i++)
    {
        if (stat[parent[i]])
            s[i]++;
    }
    root_stat[0] = stat[0];

    vector<int> cv(n, 0); // count of 1s when root is at i
    cv[0] = s[0];
    auto dfs2 = [&](auto &self, int u, int p) -> void
    {
        if (p != -1)
        {
            if ((stat[u] == 0))
            {
                root_stat[u] = 0;
                if ((cv[p] == 0))
                    cv[u]++;
            }
            else if ((stat[u] == 0) && (cv[p] > 1))
            {
                root_stat[u] = 0;
            }
            else if (cv[p] > 1) // stat[u] == 1 => root_stat[p] == 0
            {
                root_stat[u] = 1;
            }
            else
            {
                root_stat[u] = 0;
                cv[u]++;
            }
            for (auto v : g[u])
            {
                if (v != p)
                {
                    if (stat[v])
                        cv[u]++;
                }
            }
        }
        for (auto v : g[u])
        {
            if (v != p)
            {
                self(self, v, u);
            }
        }
    };

    dfs2(dfs2, 0, -1);

    int z;
    for (int i = 0; i < t; i++)
    {
        cin >> z;
        z--;
        if (!root_stat[z])
            cout << "Ron\n";
        else
            cout << "Hermione\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}